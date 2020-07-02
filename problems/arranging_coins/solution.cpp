/*
k * (k + 1) / 2 <= n
find largest k
binary search
*/
class Solution {
public:
    int arrangeCoins(int n) {
        long long start = 0;
        long long end = n;
        while (start + 1 < end) {
            long long mid = start + (end - start) / 2;
            long long sum = mid * (mid + 1) / 2;
            if (mid == n) return mid;
            if (sum < n) start = mid;
            else end = mid;
        }
        
        if (end * (end + 1) / 2 <= n) return end;
        else return start;
        
    }
};