class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);
        int k = s1.size();
        
        for (int i = 0; i < s1.size(); ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }
        
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (m1[i] == m2[i]) ++count;
        }
        
        // fixed window size
        for (int i = 0; i < s2.size() - k; ++i) {
            if (count == 26) return true;
            int r = s2[i + k] - 'a';
            int l = s2[i] - 'a';
            ++m2[r];
            if (m2[r] == m1[r]) ++ count;
            else if (m2[r] == m1[r] + 1) --count;
           
            --m2[l];
            if (m2[l] == m1[l]) ++count;
            else if (m2[l] == m1[l] - 1) --count;
        }
        return count == 26;
    }
};