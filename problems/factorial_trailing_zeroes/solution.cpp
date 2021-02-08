/*
n = 5
5! = 5 * 4 * 3 * 2 * 1
   = 5 * ()
6! = 6 * 5!
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
        
    }
};