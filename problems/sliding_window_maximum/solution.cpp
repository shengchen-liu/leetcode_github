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