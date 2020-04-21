/**

**/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> unique;
        int n = s.size();
        int i = 0;
        int j = 0;
        while (i < n && j < n) {
            if (!unique.count(s[j])) {
                unique.insert(s[j]);
                ++j;
                res = max(res, j - i);
            } else {
                while (unique.count(s[j])) {
                    unique.erase(s[i++]);  
                }
            }
        }
        
        return res;
        
    }
};