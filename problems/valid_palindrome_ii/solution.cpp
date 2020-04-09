class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                ++left; --right;
            } else {
                int l = left, r = right - 1;
                while (l < r) {
                    if (s[l] != s[r]) break;
                    ++l; --r;
                    if (l >= r) return true;
                }
                ++left;
                while (left < right) {
                    if (s[left] != s[right]) return false;
                    ++left; --right;
                }
            }
        }
        return true;
    }
};