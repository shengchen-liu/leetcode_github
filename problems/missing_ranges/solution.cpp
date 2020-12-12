class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int n = nums.size();
        
        if (n == 0) {
            res.push_back(convert(lower, upper));
            return res;
        }
        
        // missing ranges at the beginning
        if (nums[0] > lower)
            res.push_back(convert(lower, nums[0] - 1));
        
        // missing ranges betwee
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > 1)
                res.push_back(convert(nums[i - 1] + 1, nums[i] - 1));
        }
        
        // missing ranges at the end
        if (nums[n - 1] < upper)
            res.push_back(convert(nums[n - 1] + 1, upper));
        return res;
    }
    
    string convert(int l, int u) {
        if (l == u)
            return to_string(l);
        else 
            return to_string(l) + "->" + to_string(u);
    }
};