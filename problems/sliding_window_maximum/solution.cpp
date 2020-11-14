/*
1,3,-1,-3,5,3,6,7, k = 3
1  3  -1 -3  5  3  6  7    deque(idx)                    max
i      j                   [1, 2]                    3
i         j                [1, 2, 3]          3
   i      j                [2, 3]              3
   i         j             [5]         5
       i     j             [5]              5
       i        j          [5, 3]          5
          i     j          [5, 3]               5
          i        j       [6]           ?
             i     j       [6]                6
             i        j    [7]            ?
                i     j    [7]                7
deque dq
max
for i from 0 to k-1:
    initialize dq
    while (val > dq.back()){
        dq.pop_back()
    }
    dq.push_back(val)
    
for i from k to n - 1:
    push val to dq
    if nums[i] == dq.front:
        dq.pop_front
    res.push_back(dq.front())
            
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            
            // if we have enough elements
            if (i - k + 1 >= 0) res.push_back(nums[q.front()]);
            // check if the first element in the window is the max element
            if (i - k + 1 == q.front()) q.pop_front();
        }
        return res;
    }
};