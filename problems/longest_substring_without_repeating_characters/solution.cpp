/*
a  b  c  a  b  c  b  b    cur    hashmap
ij                        a      a
i  j                      ab     a,b
i     j                   abc    a, b, c
i        j                x
   i     j                bca    b:1 c:1 a:1
   i        j             x      b:2 c:1 a:1
      i     j             cab    b:1 c:1 a:1
      i        j          x      b:1 c:2 a:1
         i     j          abc    b:1 c:1 a:1
         i        j       x      b:2 c:1 a:1
            i     j       x      b:2 c:1
                i j       cb     b:1 c:1
                i    j    x      b:2 c:1
                   i j    x      b:2
                     ij   b      b:1
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visited;
        int res = 0;
        int n = s.size();
        
        // sliding window
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while(j < n && !visited.count(s[j])) {
                visited.insert(s[j]);
                ++j;
            }
            res = max(res, j - i);
            visited.erase(s[i]);
        }
        return res;
    }
};