/*
Given s1, s2, how to judge that if s1 is the substring of s2?
s1 = "ab" s2 = "eidbaooo"
s1_map:
'a' : 1
'b' : 1

build a hashmap that contains fisrt m elements
'e' : 1
'i' : 1
compare s1_map == s2_map : true : sliding to the right

*/
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
        
        // fixed window size: m1.size()
        for (int i = 0; i < s2.size() - k; ++i) {
            if (count == 26) return true;
            // sliding right
            int r = s2[i + k] - 'a';
            int l = s2[i] - 'a';
            ++m2[r];
            if (m2[r] == m1[r]) ++count;
            else if (m2[r] == m1[r] + 1) --count;
           
            --m2[l];
            if (m2[l] == m1[l]) ++count;
            else if (m2[l] == m1[l] - 1) --count;
        }
        return count == 26;
        
        
    }
};