/*
0 1 0 0
0 1 0 x

1 1 | 1 1
11110
10101: 3
11011
s1:
10101
s2:
01010
dp[i]: min num of operations for the first i elems
dp[0] = 0

*/
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string s1, s2;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {  //s1:'1', s2: '0'
                s1.push_back('1');
                s2.push_back('0');
            } else {
                s1.push_back('0');
                s2.push_back('1');
            }
        }
        
        // compare
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != s1[i])
                ++cnt1;
            if (s[i] != s2[i])
                ++cnt2;
        }
        return min(cnt1, cnt2);
    }
};