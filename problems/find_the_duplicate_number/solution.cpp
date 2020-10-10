/*
[1 , n]  n + 1

1, 3, 4, 2, 2

idea 1: sort nums (O(n log(n)))
1, 2, 2, 3, 4 o(n) , o (log(n))

idea 2: counting
bucket size: n + 1
idx: 0, 1, 2, ..., n n = 5
   [0, 0, 0, 0, 0, 0]
1: [0, 1, 0, 0, 0, 0]
3: [0, 1, 0, 1, 0, 0]
4: [0, 1, 0, 1, 1, 0]
2: [0, 1, 1, 1, 1, 0]
2: [0, 1, 1[x], 1, 1, 0]

idea 3: 
0 -> 1
1 -> 3
2 -> 4
3 -> 2
4 -> 2
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};