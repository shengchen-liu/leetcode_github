class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);
        int k = s1.size();
        
        for (int i = 0; i < k; ++i) {
            ++m1[s1[i] - 'a'];
            ++m2[s2[i] - 'a'];
        }
        
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (m1[i] == m2[i]) ++count;
        }
        
        // fixed window size: k
        for (int i = 0; i < s2.size() - k; ++i) {
            if (count == 26) return true;
            // sliding right
            int r = s2[i + k] - 'a';
            int l = s2[i] - 'a';
            ++m2[r];
            if (m1[r] == m2[r]) ++count;
            else if (m1[r] + 1 == m2[r]) --count;
            
            // left
            --m2[l];
            if (m1[l] == m2[l]) ++count;
            else if (m1[l] - 1 == m2[l]) --count;
        }
        return count == 26;
    }
};