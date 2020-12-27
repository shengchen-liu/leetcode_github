/*
text | book
1      2
*/
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int cnt_a  = 0;
        int cnt_b  = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (vowels.count(s[i]))
                ++cnt_a;
        }
        for (int i = n / 2; i < n ; ++i) {
            if (vowels.count(s[i]))
                ++cnt_b;
        } 
        return cnt_a == cnt_b;
    }
};