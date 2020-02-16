class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int l = 0;
        int res = 0;
        unordered_map<char, int> hashmap;
        for (int r = 0; r < n; ++r) {
            ++hashmap[s[r]];
            while (hashmap.size() > 2) {
                --hashmap[s[l]];
                if (hashmap[s[l]] == 0) {
                    hashmap.erase(s[l]);
                }
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};