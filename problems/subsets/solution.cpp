class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out; // leaf
        getSubsets(nums, 0, out, res);
        return res;
    }
    
    void getSubsets(vector<int>& nums, 
                    int pos, 
                    vector<int> &out, 
                    vector<vector<int>> &res) {
        if (pos == nums.size()) {
            res.push_back(out);
            return;
        }
        // add 
        out.push_back(nums[pos]);
        getSubsets(nums, pos + 1, out, res);
        out.pop_back();
        // don't add the current val
        getSubsets(nums, pos+1, out, res);
    }
};