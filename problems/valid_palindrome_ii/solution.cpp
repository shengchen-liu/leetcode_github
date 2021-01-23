/*
a b c a
i     j

1. s[i] == s[j] : ++i, --j
2. s[i] != s[j] : cnt = 1.  
    1) . validPalindrome(i + 1, j)
    2) validPalindrome(i, j - 1)
    
*/
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0; 
        int j = n - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return (helper(s, i + 1, j) || helper(s, i, j - 1));
            }
            ++i;
            --j;
        }
        return true;
    }
    
    bool helper(string s, int i, int j) {
        int n = s.size();
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};