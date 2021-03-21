/*
n, idx, maxSum
constrct an array nums
s.t.:
1. nums.length == n
2. nums[i] > 0
3. abs(two neibhors's difference) <= 1
4. sum <= maxSum
5. maximize nums[idx]

e.g:
n=4, idx=2, maxSum=6

0 1 2* 3   sum
1 1 2  1   5
1 2 2  1   6 

return 2
maxSum = 10
0 1* 2 3 4 5   sum
1 1  1 1 1 1   6
1 2  1 1 1 1   7
2 2  1 1 1 1   8
2 2  2 1 1 1   9
2 3  2 1 1 1   10

0 1 2 3 4 5   sum
1 1 1 1 1 1   6
1 2 1 1 1 1   7
2 3 2 1 1 1   7 + 3 =10
3 4 3 2 1 1   10 + 4 = 14

two pointers : left ,right 

optimazation:
log(n)

sum of the pyramid: 
[n, maxSum]
if I build a pyramid with a value 'v' inside this range: 
    the peak of this pyramid should  be considered as a possible answer

6, 10
mid = 8
mid = (lower + upper) / 2

*/
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1;
        int right = maxSum;
        int res = 1;  // pyrmaid's height
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool success = check(n, index, maxSum, mid);
            if (success) {
                res = mid;
                left =  mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
    
    bool check(int n, int index, int maxSum, int peak) {
        long sum = getSum(peak, index + 1) + getSum(peak, n - index) - peak;
        return sum <= (long) maxSum;
    }
    
    long getSum(long peak, int length) {
        long sum = 0;
        if (length > peak) {
            sum += (1 + peak) * peak / 2;
            sum += (length - peak);
        } else {
            long minumum = peak - length + 1;  //3
            sum += (minumum + peak) * length / 2;
        }
        return sum;
    }

};