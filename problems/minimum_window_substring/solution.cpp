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
        for (char c : t) ++letterCnt[c];
        unordered_map<char, int>  sourceCnt;
        int j = 0;
        int cnt = 0; // num. of letters that have same frequences with target
        int minLen = INT_MAX;
        for (int i = 0; i < s.size(); ++i) {
            while (j < s.size() && cnt < letterCnt.size()) {
                if (letterCnt.count(s[j])) {
                    sourceCnt[s[j]]++;
                    if (sourceCnt[s[j]] == letterCnt[s[j]])
                        ++cnt;
                }
                ++j;
            }
            
            if (j - i < minLen && cnt == letterCnt.size()){
                minLen = j - i;
                res = s.substr(i, minLen);
            }
            
            // remove i and move forward
            if (letterCnt.count(s[i])) {
                if (letterCnt[s[i]] == sourceCnt[s[i]])
                    --cnt;
                sourceCnt[s[i]]--;
            }
        }
        return res;
    }
};