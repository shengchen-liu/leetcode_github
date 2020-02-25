/**
sqrt(x)
sqrt(8) = 2
1, 2, 3, 4, 5, 6, 7, 8

5^2 = 25 > 8 => [1, 2, 3, 4]
3^2 = 9 > 8 => [1, 2]
2^2 = 4 < 8 => [] => return 2

**/
class Solution {
public:
    int mySqrt(int x) {
        long start = 1;
        long end = x;
        while (start + 1 < end) {
            long mid = start + (end - start) / 2;
            if (mid * mid <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (end * end <= x) return end;
        return start;
    }
};