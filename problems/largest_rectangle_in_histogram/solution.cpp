/*
deque: store idx.  Values in ascending order.  Only push new idx into the dequeu if its value >= deque's last element value
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        deque<int> dq;
        dq.push_back(-1);
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            while (dq.back() != -1 && heights[dq.back()] >= heights[i]) {
                int curHeight = heights[dq.back()];
                dq.pop_back();
                int curWidth = i - dq.back() - 1;
                maxArea = max(maxArea, curHeight * curWidth);
            }
            dq.push_back(i);
        }
        while (dq.back() != -1) {
            int curHeight = heights[dq.back()];
            dq.pop_back();
            int curWidth = n - dq.back() - 1;
            maxArea = max(maxArea, curHeight * curWidth);
        }
        return maxArea;
    }
};