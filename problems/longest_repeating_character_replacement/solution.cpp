class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0;
        int maxCnt = 0; // count of the char that appearst the most frequently
        int i = 0; 
        int j = 0;
        vector<int> count(26, 0);
        while (j < n) {
            count[s[j] - 'A']++;
            maxCnt = max(maxCnt, count[s[j] - 'A']);
            while (j - i + 1 - maxCnt > k) {
                --count[s[i] - 'A'];
                ++i;
            }
            res = max(res, j - i + 1);
            ++j;
        }
        return res;
    }
};