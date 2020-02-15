class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        // sort
        sort(nums.begin(), nums.end());
        // nums[p1] + nums[p2] + nums[p3] vs. target
        int min_dist = INT_MAX;
        for (int i = 0; i < n - 2; ++i) { // p1
            int j = i + 1;
            int k = n - 1;
            
            // 2 sum
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if (min_dist > diff) {
                    min_dist = diff;
                    res = sum;
                }
                if (sum < target) ++j;
                else --k;
            }
        }
        return res;
    }
};