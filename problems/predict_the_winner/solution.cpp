class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        return winner(nums, 0, n - 1, memo) >= 0;
    }
    
    // return the score in the range [start, end]
    int winner(vector<int>& nums, int start, int end, vector<vector<int>> &memo) {
        // termination
        if (start == end)
            return nums[start];
        
        // recursion
        if (memo[start][end] != INT_MAX){
            return memo[start][end];
        }
        
        int a = nums[start] - winner(nums, start + 1, end, memo);
        int b = nums[end] - winner(nums, start, end - 1, memo);
        memo[start][end] = max(a, b);
        return memo[start][end];
    }
};