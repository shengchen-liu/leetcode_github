/*
01234
hello  ll
i      j
 i     j
  i    j
   i    j

haystack[i] vs. needle[j]
if !=:
    ++i
    j = 0
if ==:
    ++i
    ++j
    if j == needle.size() return true
    
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};