/*
on each row, count how many # of consecutive 1's on the top.
now this becomes to "find the largest rectangle in a histogram" problem
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> countOnes(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    if (matrix[i][j] == '1')
                        countOnes[i][j] = 1;
                } else {
                    if (matrix[i][j] == '1')
                        countOnes[i][j] = countOnes[i - 1][j] + 1;
                }
            }
        }
        
        // search each row
        int res = 0;
        for (int i = 0; i < m; ++i) {
            res = max(res, maxRec(countOnes, i));
        }
        return res;
    }
    
    int maxRec(vector<vector<int>> &countOnes, int bottom) {
        stack<int> st;
        st.push(-1);
        int maxArea = 0;
        int n = countOnes[0].size();
        
        for (int i = 0; i < n;  ++i) {
            while (st.top() != -1 && countOnes[bottom][i] <= countOnes[bottom][st.top()]) {
                int top = st.top();
                st.pop();
                maxArea = max(maxArea, countOnes[bottom][top] * (i - st.top() - 1));
            }
            st.push(i);
        }
        
        while (st.top() != -1) {
            int top = st.top();
            st.pop();
            maxArea = max(maxArea, countOnes[bottom][top] * (n - st.top() - 1));
        }
        return maxArea;
    }
};