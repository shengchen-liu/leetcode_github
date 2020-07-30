class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        int i = 0;
        int j = 0;
        int n = s.size();
        int res = 0;
        unordered_set<char> visited;
        while (i < n) {
            if (!visited.count(s[i])) {
                visited.insert(s[i]);
                ++i;
                res = max(res, i - j);
            } else {
                while (visited.count(s[i])) visited.erase(s[j++]);
            }
        }
        return res;
        
    }
};