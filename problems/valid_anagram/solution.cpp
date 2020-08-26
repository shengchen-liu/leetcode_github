class Solution {
public:
    bool isAnagram(string s, string t) {
        // hashtable
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
            --m[t[i]];
        }
        
        for (auto a : m) {
            if (a.second != 0) return false;
        }
        
        return true;
    }
};