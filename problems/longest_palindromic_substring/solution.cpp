class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int n = s.size();
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen){
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right])
                break;
            --left;
            ++right;
        }
        if (right -  left - 1 > maxLen){
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};