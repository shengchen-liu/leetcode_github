/*
1001  one
i     t
   i
   
s[i] == 1 AND seen == true AND s[i-1] == 0

*/
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seenOne = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (!seenOne)
                    seenOne = true;
                else {
                    if (s[i - 1] == '0')
                        return false;
                }
            }
        }
        return true;
    }
};