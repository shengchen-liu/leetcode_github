class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashmap;
        
        for (string word : strs) {
            vector<int> count(26);
            string t;
            for (char c : word) {
                ++count[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                if (count[i] > 0) {
                    t += string(1, i + 'a') + to_string(count[i]);
                }
            }
            hashmap[t].push_back(word);
        }
        
        for (auto a : hashmap) {
            res.push_back(a.second);
        }
        
        return res;
        
    }
};