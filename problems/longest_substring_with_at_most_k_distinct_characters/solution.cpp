class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        unordered_map<char, int> m;
        int i = 0;
        int j = 0;
        int n = s.size();
        while (j < n) {
            ++m[s[j]];
            while (m.size() > k) {
                if (--m[s[i]] == 0) m.erase(s[i]);
                ++i;
            }
            res = max(res, j - i + 1);
            ++j;
        }
        return res;
    }
};