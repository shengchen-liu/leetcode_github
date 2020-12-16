/*
0  1  2  3  4  5  6
1, 2, 3, 4, 5, 6, 7 k = 3
         1  2  3  4
0  1  2  3  4  5  6  
1, 2, 3, 4, 5, 6, 7  
         1  2  3  4  
k = k % n
for i from 0 to n - 1:
    nums[(i+k) % n] = tmp[i]
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
                if (nums.empty() || (k %= nums.size()) == 0) return;
        int start = 0, idx = 0, pre = 0, cur = nums[0], n = nums.size();
        for (int i = 0; i < n; ++i) {
            pre = cur;
            idx = (idx + k) % n;
            cur = nums[idx];
            nums[idx] = pre;
            if (idx == start) {
                idx = ++start;
                cur = nums[idx];
            }
        }
    }
};