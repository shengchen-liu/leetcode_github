class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for (auto word : strs) {
            vector<int> cnt(26);
            string t;
            for (char c : word) {
                ++cnt[c - 'a'];
            }
            
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    t += string(1, i + 'a') + to_string(cnt[i]);
                }
            }
            m[t].push_back(word);
        }
        
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};