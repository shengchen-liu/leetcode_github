/*
idx 0 1 2 3 4 ... 15
    * * * * * ...  *
    1   1   
dp[s][i]: min cost to distribute a set of nums representd by binary mask,the last number in this set is nums[i]

initi: dp[*][*] = max_int
        dp[1<<i][i] = 0, cost of selecting a single number is zero
        
transition: 
1. if s % (n / k) == 0, we start a new group, no extra cost
    dp[s | (1 << j)][j] = dp[s][i]
2. In the same group, we requre the selected numbers are monotonically increasing.  Each cost is nums[j] - nums[i]
*/
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int c = n / k;
        int dp[1<<16][16]; // min cost to distribute a set of nums representd by binary mask,the last number in this set is nums[i]
        memset(dp, 0x7f, sizeof(dp)); // 0x7f: 0111_1111
        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = 0;
        
        for (int s = 0; s < 1 << n; ++s) {
            for (int i = 0; i < n; ++i) {
                if ((s & (1 << i)) == 0)
                    continue; // skip if nums[i] is not the last elem in set
                for (int j = 0; j < n; ++j){
                    if ((s & (1 << j)))
                        continue; // skip if j is already in the set
                    int t = s | (1 << j);  // add j into the set
                    if (__builtin_popcount(s) % c == 0) {
                        // 1.  if (number of elems in s) % (n / k) == 0
                        dp[t][j] = min(dp[t][j], dp[s][i]);
                    } else if (nums[j] > nums[i]) {
                        dp[t][j] = min(dp[t][j], dp[s][i] + nums[j] - nums[i]);
                    }
                }
            }
        }
        int res =  *min_element(begin(dp[(1 << n) - 1]), 
                           end(dp[(1 << n) - 1]));
        return res > 1e9? -1 : res;
    }
};