/*
a binary string s
alternating: no two adjacent characters are equal
step: swap two charcters
min number of swaps?

eg:
111000
101010 option1
010101 option2
which option is better?

how to determine whether a string is alternating?
'xor' operation from 1st digit to the last
101
1 ^ 0 = 1
0 ^ 1 = 1

                [1]11000
       111000               011000        
                


*/

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        
        // count # of 0 and # of 1
        int cnt_0 = 0;
        int cnt_1 = 0;
        for (char c : s) {
            if (c == '0')
                cnt_0++;
            else 
                cnt_1++;
        }
        
        // diff > 1
        if (abs(cnt_0 -  cnt_1) > 1)
            return -1;
        
        int res = INT_MAX;
        // 3 cases: 
        if (cnt_0 > cnt_1) {
            int cnt = 0;
            // 0101...0
            for (int i = 0; i < n; ++i) {
                char cmp = i % 2 == 0 ? '0': '1';
                if (s[i] != cmp)
                    ++cnt;
            }
            cnt = cnt / 2;
            res = min(res, cnt);
        } else if (cnt_0 < cnt_1) {
            // 101...1
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                char cmp = i % 2 == 0 ? '1': '0';
                if (s[i] != cmp)
                    ++cnt;
            }
            cnt = cnt / 2;
            res = min(res, cnt);
        } else {
            int cnt_1 = 0;
            int cnt_2 = 0;
            // 0101...0
            for (int i = 0; i < n; ++i) {
                char cmp_1 = i % 2 == 0 ? '0': '1';
                char cmp_2 = i % 2 == 0 ? '1': '0';
                if (s[i] != cmp_1)
                    ++cnt_1;
                if (s[i] != cmp_2)
                    ++cnt_2;
            }
            res = min(min(res, cnt_1 / 2), cnt_2 / 2);
        }
        return res;
    }
};