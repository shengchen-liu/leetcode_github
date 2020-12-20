/*
nums, k
one move: jump <= k steps, without going out
want to reach to the last idx
record score. maximize the score

k = 2
x             t    score
0  1  2  3  4 5     
1,-1,-2, 4,-7,3
i                   1
   i                0
         i          4
              i     7
              
1. similar jumping stairs
dp[i] : max score a person can get for the first i stairs.  the person is currently at stair i
vs.dp[j]: at most k steps

for i from 0 to n - 1:
    j from 1 to k:
        dp[i] = max(dp[i], dp[i - j] + nums[i])

initial con:
dp[0] = nums[0]

dp[n-1]
 
2. optimzation
for a given i :
    maintain a data strcture to tell me the max val of previous k elements => O(1)
    
max value in sliding window
deque: only stores values that > current nums[i].  

descending order
fron       back
oldest     newest elemtn

*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        deque<int> dq; // only stores idx
        dq.push_back(0);
        
        // iteratrion
        for (int i = 1; i < n; ++i) {  // O(N)
           // old idx is beyond the range of k -> remove it
            while (!dq.empty() && dq.front() < i - k) 
                dq.pop_front();
            
            // update dp
            dp[i] = dp[dq.front()] + nums[i];  
            
            // pop out all values < nums[i]
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};