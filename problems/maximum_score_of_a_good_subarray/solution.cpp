/*
sliding window
min(window) * window_length => score
k must be contained inside this window
max score

window_size = 1

gloab_max
0  1  2  3* 4  5
1  4  3  7  4  5
         ij
           i
   i     j
i        j
i           j
i              j
    
while (i >0 and j )
if min()
A[i - 1] < A[j + 1]


*/
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k]; // global max
        int curMin = nums[k];
        int n = nums.size();
        int i = k;
        int j = k;
        
        while (i > 0 || j < n - 1) {
            // cout << "i:" << i << "j: " << j << endl;
            if (i == 0)
                ++j;
            else if (j == n -1) {
                --i;
            }
            else if (nums[i - 1] < nums[j + 1])
                ++j;
            else 
                --i;
            curMin = min(curMin, min(nums[i], nums[j])); // 
            res = max(res, curMin * (j - i + 1));
        }
        return res;
    }
};