/*
nums.
subarray: continous.  contains unque ele
score: sum of all elems
nums = [4,2,4,5,6]
                  score    max
4  2  4  5  6   
ij                4         4
i  j              6         6
i     j           x 
   2  4           6         6
   i     j        11        11
   i        j     17        17

sliding window

*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int j = 0;
        int n = nums.size();
        int score = 0;
        unordered_set<int> visited;
        for (int i = 0; i < n; ++i) {
            while (j < n  && !visited.count(nums[j])) {
                score += nums[j];
                res = max(res, score);
                visited.insert(nums[j]);
                ++j;
            }
            // cout << res << endl;
            // if (j == n)
            //     return res;
            score -= nums[i];
            visited.erase(nums[i]);
            
        }
        return res;
    }
};