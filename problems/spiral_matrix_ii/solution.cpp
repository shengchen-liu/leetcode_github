class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; ++layer) {
            // top
            for (int i = layer; i < n - layer; ++i) {
                res[layer][i] = cnt++;
            }
            // right
            for (int i = layer + 1; i < n - layer; ++i) {
                res[i][n - layer - 1] = cnt++;
            }
            // bottom
            for (int i = n - layer - 2; i >= layer; --i) {
                res[n- layer - 1][i] = cnt++;
            }
            // left
            for (int i = n - layer - 2; i > layer; --i) {
                res[i][layer] = cnt++;
            }
        } 
        return res;
    }
};