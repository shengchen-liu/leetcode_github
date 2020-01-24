class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> hashset;
            int len = 0;
            for (int j = i; j < s.size(); j++){
                if (hashset.count(s[j])) break;
                hashset.insert(s[j]);
                len++;
                max_len = max(max_len, len);
            }
        }
        return max_len;
        
    }
};