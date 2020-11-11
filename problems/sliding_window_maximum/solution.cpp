/*
k=3                          deque           Max
[1, 3, -1] -3, 5, 3, 6, 7    [0, 1, 2]     3
1 [3  -1  -3] 5  3  6  7     [3, -1]       
                             [3, -1, -3]    3
1  3 [-1  -3  5] 3  6  7     [-1, -3]    
                             [5]            5
1  3  -1 [-3  5  3] 6  7     [5]      
                             [5, 3]         5
1  3  -1  -3 [5  3  6] 7     [5, 3]        
                             [6]            6 
1  3  -1  -3  5 [3  6  7]    [6]        
                             [6 7]          7

1. init deque with first k elements
2. iterate over the array:
    a) clean the deque:
        (1) keep only idx in current window.  len == k?
        (2) remove all elemets that are < current element
    b) append current to the deque
    c) append dequep[0] to the output
                               
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