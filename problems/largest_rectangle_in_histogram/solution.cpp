/*
2 1 5 6 2 3

monotonic stack:  only keep increasing heights
for each height:
    if height >= st.top:
        st.push(height)
    else:
        until st.top > height or st.empty:
            compute area(cur, st.top)
            updat maxArea
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st .top();
                st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};