/*
balanced strings: equal # of "L" and "R"
RL | RRLL | RL | RL
RL RRLL RL RL
10 1210 10 10

RL L L L  R R R | LR
10 -1-2-3-2 -10   -10
*/
class Solution {
public:
    int balancedStringSplit(string s) {
        int sum = 0;
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R')
                ++sum;
            else 
                --sum;
            if (i > 0 && sum == 0) 
                ++res;
        }
        return res;
    }
};