class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> res;
        int k = p.size();
        vector<int> ms(26, 0);
        vector<int> mp(26, 0);
        
        // fixed window size of k
        for (int i = 0; i < k; ++i) {
            ++ms[s[i] - 'a'];
            ++mp[p[i] - 'a'];
        }
        
        // number of same freq
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (ms[i] == mp[i]) ++cnt;
        }
        
        // sliding window
        for (int i = 0; i < s.size() - k; ++i) {
            if (cnt == 26) res.push_back(i);
            // right and left value
            int r = s[i + k] - 'a';
            int l = s[i] - 'a';
            
            ++ms[r];
            if (ms[r] == mp[r]) ++cnt;
            else if (ms[r] == mp[r] + 1) --cnt;
            
            --ms[l];
            if (ms[l] ==  mp[l]) ++cnt;
            else if (ms[l] == mp[l] - 1) --cnt;
        }
        
        if (cnt == 26) res.push_back(s.size() - k);
        return res;
    }
};