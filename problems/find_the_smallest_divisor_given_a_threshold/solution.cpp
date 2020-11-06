/*
[1,2,5,9], threshold=6
d
1/d + 2/d + 5/d + 9/d = sum
sum <= 6

threshold : [n, 10^6]
d: max_nums (9) => sum <= n upper_limit
lower_limit: 1
find d in range of [lower, upper]
Binary search:
mid = L + (U -L)/2
calcluate sum based on M
1) sum > threshold:
    L = mid
2) sum <= threshold:
    U = mid

mid
*/
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // find max num
        int left = 1;
        int right = 0;

        for (int num : nums) {
            right = max(right, num);
        }
        
        while (left < right) {
            int sum = 0;
            int mid = left + (right - left) / 2;
            for (int i : nums) {
                sum += (i + mid - 1) / mid;
            }
            if (sum > threshold) left = mid + 1;
            else right = mid;
            // cout << sum <<endl;
        }
        
        return left;
    }
};