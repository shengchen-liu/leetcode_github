/**
dp[0]: -2
dp[1]: -2 + 0
dp[2]: -2 + 3 = 1
dp[3]: 1 - 5 = -4
dp[k]: dp[k-1] + nums[k]

sumRange[i, j] = dp[j] - dp[i] + nums[i]
**/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        dp = nums;
        if (nums.size() != 0){
            dp[0] = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                dp[i] = dp[i - 1] + nums[i];
            }            
        }

        
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return dp[j];
        return dp[j] - dp[i - 1]; 
    }
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */