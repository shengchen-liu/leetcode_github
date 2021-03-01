/*
cba                               cost
abcdefghijklmnopqrstuvwxyz
i                                  0
  i                                2
 i                                 2+1=3
i                                  3+1=4  

*/
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> m;
        int n = keyboard.size();
        for (int i = 0; i < n; ++i) {
            m[keyboard[i]] = i;
        }
        
        int idx = 0;
        int res = 0;
        for (int i = 0; i < word.size(); ++i) {
            res += abs(m[word[i]] - idx);
            idx = m[word[i]];
        }
        return res;
    }
};