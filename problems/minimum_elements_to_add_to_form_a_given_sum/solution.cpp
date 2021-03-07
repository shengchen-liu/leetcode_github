/*
nums.  abs(nums[i]) <= limit
limit, goal

min number of elments need to add nums. s.t sum == goal

nums: [1, -1, 1]
limit: 3
goal: -4

sum: 1  vs. goal: -4
-3, -2 => sum: -4
return 2

sum vs. goal
diff = abs(sum, goal)
ceiling integer
(diff + limit -1) / limit


*/
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long int sum = 0;
        
        for (int num : nums) {  // list iterator 
            sum += num;
        }
        
        long int diff =  abs(sum - goal);
        return ceil((double) diff / limit);
        // return (diff + limit - 1) / limit;
    }
};