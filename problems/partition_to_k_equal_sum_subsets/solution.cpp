class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        if (total_sum % k != 0)
            return false;
        sort(nums.begin(), nums.end(), greater<int>()); // descending order
        vector<bool> visited(nums.size(), false);
        return dfs(nums, k, total_sum / k, 0, 0, visited);
    }
    
    // backtracking
    bool dfs(vector<int>& nums, int k, int target, int start, int cur_sum, vector<bool> &visited) {
        // termination
        if (k == 1) return true;
        if (cur_sum > target) return false;
        if (cur_sum == target)
            return dfs(nums, k - 1, target, 0, 0, visited);
        
        // recursion
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i])
                continue;
            visited[i] = true;
            if (dfs(nums, k, target, i + 1, cur_sum + nums[i], visited))
                return true;
            visited[i] = false;
        }
        return false;
    }
};