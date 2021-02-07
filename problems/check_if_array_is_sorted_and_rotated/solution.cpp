/*
3,4,5,1,2
i
      i
nums[i] <= nums[i+1]: ++i
nums[i] > nums[i+1] AND rotate==false: ++i
nums[i] > nums[i+1] AND rotate==true: return false
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == sorted[(i + j) % n]) {
                    ++cnt;
                } else {
                    break;
                }
            }
            if (cnt == n)
                return true;
        }
        return false;
    }
};