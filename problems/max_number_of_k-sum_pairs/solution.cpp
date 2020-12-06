/*
nums = [1,2,3,4], k = 5
1. sort
[1, 2, 3, 4]
2. k = 6
1 2 3 4 6    sum      cnt
i       j     x       0
i     j       5<k     0
  i   j       6==k    1
    i,j

2. idx i, j
i=0, j = n-1
while i < j:
    sum = nums[i] + nums[j]
    sum vs k.  
    move i, j
    
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        // 1. sort
        sort(nums.begin(), nums.end());
        
        // 2. iteration
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            // j is too large
            if (nums[j] >= k){
                --j;
                continue;
            }
            int sum = nums[i] + nums[j];
            if (sum == k) {
                ++cnt;
                ++i;
                --j;
            } else if (sum > k) {
                --j;
            } else {
                ++i;
            }
        }
        return cnt;
    }
};