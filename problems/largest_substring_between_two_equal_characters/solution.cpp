/*
s = "abca" => 2
s = "cabbac" => 
abba, bb => 4

sliding windwo: i, j
iterate from left to right, keep record of the largest window size.
window satsify criteria: substring between two equal characters

start 0 to end of the string

*/
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        int i = 0;
        int j = 0;
        for (i; i < s.size(); ++i) {
            // right index
            j = i + res + 2;// improve
            while (j < s.size()) {
                if (s[i] == s[j]) {
                    res = max(res, j - i - 1);
                }
                ++j;
            }
            
        }
        return res;
    }
};