/*
nums, goal
sum of the subsequence of nums is close to goal
return min abs(sum - goal)

nums: [5, -7, 3, 5], goal:6
5 - 7 + 3 + 5 = 6

nums: [7,-9,15,-2], goal: -5
7, -9, -2 = -4

divide the array into two parts of nearly is equal size
for one part:
    consider all subsets.
    make a list of all possible subset sums and sort this list
for the other part:
    consider all subsets of this part, for each part:
        let sum = x.
        binary search to get the nearest possible value to goal-x in the first part

7, -9, 15, -2 => [7, -9], [15, -2]
meet in the middle
A: [0, 7, -9, -2] -> 
   [-9, -2, 0, 7]
     x
B: [0, 15, -2, 13] -> 
    [-2, 0, 13, 15]
x + y vs. target = -5

x     y     sum     vs. target   min_dist
-9    -2    -11      <           6
-9    0     -9       <           4 
-9    13    4        >           4
-2    13    11       >           4

*/
class Solution {
public:
    vector<int> generate(const vector<int> &vec) {
        int n = vec.size();
        vector<int> sums = {0};
        for (int v : vec) {
            int n = sums.size();
            for (int i = 0; i < n; ++i) {
                sums.push_back(v + sums[i]);
            }
        }
        return sums;
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> first_half(nums.begin(), nums.begin() + nums.size() / 2);
        vector<int> second_half(nums.begin() + nums.size() / 2, nums.end());
        
        vector<int> first_subset = generate(first_half);
        vector<int> second_subset = generate(second_half);
        
        sort(second_subset.begin(), second_subset.end());
        
        int res = INT_MAX;
        for(int i = 0; i < first_subset.size(); ++i) {
            auto it = lower_bound(second_subset.begin(), second_subset.end(), goal - first_subset[i]);
            if (it != second_subset.end()) {
                res = min(res, abs(goal - *it - first_subset[i]));
            }
            if (it != second_subset.begin()) {
                res = min(res, abs(goal - *(--it) - first_subset[i]));
            }
        }
        return res;
    }
};