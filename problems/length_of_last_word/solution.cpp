class Solution {
public:
    int lengthOfLastWord(string s) {
        int p = s.size() - 1;
        int len = 0;
        while (p >= 0) {
            if (s[p] != ' ') {
                ++len;
            } else if (len > 0) {
                return len;
            }
            --p;

        }
        return len;
    }
};