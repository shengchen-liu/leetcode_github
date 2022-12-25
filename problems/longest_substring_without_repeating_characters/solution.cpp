class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visited;
        int res = 0;
        int n = s.size();
        
        // sliding window
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while(j < n && !visited.count(s[j])) {
                visited.insert(s[j]);
                ++j;
            }
            res = max(res, j - i);
            visited.erase(s[i]);
        }
        return res;
    }
};