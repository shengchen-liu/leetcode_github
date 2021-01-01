class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top();  // 0
                st.pop();  //st:[]
                res = max(res, heights[cur] * (st.empty() ? i : (i  - st.top() - 1)));
            }
            st.push(i);
        }
    
        return res;
    }
};