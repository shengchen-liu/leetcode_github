/*
abccccdd
a:1
b:3 (y)
c:4 (y)
d:2 (y)

palindrome:
*** | ***
***[?]***
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        int max_odd = 0;
        int n = s.size();
        unordered_map<char, int> m;
        
        for (char c : s) {
            m[c]++;
        }
                
        for (auto a : m) {
            int v = a.second;
            res += a.second / 2 * 2;
            if (res % 2 == 0 && v % 2 == 1)
                ++res;
        }

        return res;
        
    }
};