class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        int left = 0;
        int n = s.size();
        unordered_map<char, int> hashmap;
        for (int i = 0; i < n; ++i) {
            ++hashmap[s[i]];
            while (hashmap.size() > k) {
                --hashmap[s[left]];
                if (hashmap[s[left]] == 0) hashmap.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};