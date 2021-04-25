/*
n = 34 (10)
k = 6

34(6) = ?
a * 6^1 + b * 6^0
a = 5, b = 4

highest digit?
34 / 6 = 5 > 0
34 % 6 = 4 (b)
5 % 6 = 5 (a)
*/

class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while (n > 0) {
            res += n % k;
            n = n / k;
        }
        return res;
    }
};