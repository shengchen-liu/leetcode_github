/*
s = "ADOBECODEBANC", t = "ABC"
hashmap:
A: 1
B: 1
C: 1
ADOBECODEBANC     map           cnt    
ij                A:0 B:1 C:1   1 
i j               A:0 B:1 C:1   1
i  j              A:0 B:0 C:1   2
i   j             A:0 B:0 C:1   2
i    j            A:0 B:0 C:0   3    move left, update min_len
 i   j            A:1 B:0 C:0   2    move     
 i       j        A:0 B:0 C:0   3    move left
  i      j        A:0 B:0 C:0
   i  j 
   i   j
   i    j
   i     j
   i      j                 B:2, C:1
   i       j                A:1, B:2, C:1
*/
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};