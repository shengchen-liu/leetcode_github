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