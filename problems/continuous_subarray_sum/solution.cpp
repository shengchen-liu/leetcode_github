/*
若数字a和b分别除以数字c，若得到的余数相同，那么(a-b)必定能够整除c。

*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> m{{0, -1}}; //[余数， 该余数第一次出现的index]
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if (m.count(t)) {
                if (i - m[t] > 1) return true;
            } else m[t] = i;
        }
        return false;
    }
};