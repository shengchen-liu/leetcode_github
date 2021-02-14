/*
min max
nums: [9]
maxOps: 2
1. [9] -> [6, 3]
2. [6,3] -> [3,3,3]

2,4,[8],2
each step, we want to split the largest ball
8->
[1,7], [2,6], [3, 5], [4,4]

7, [17]
17: [1, 16], [2,15], [3, 14], [4, 13], [5,12], [6, 11], [7, 10], [8, 9]

suppose 1 op remaining: res = 2nd largest ball 
*/
class Solution {
public:
    int minimumSize(vector<int>& A, int k) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2; 
            int ops = 0;
            for (int a : A)
                ops += (a - 1) / mid;
            if (ops > k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};