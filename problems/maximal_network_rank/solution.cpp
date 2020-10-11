class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<int> m(n, 0);
        for (auto road : roads) {
            int a = road[0];
            int b = road[1];
            if (a < b) {
                matrix[a][b] = 1;
            } else {
                matrix[b][a] = 1;
            }
            ++m[a];
            ++m[b];
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = m[i] + m[j] - matrix[i][j];
                res = max(res, tmp);
            }
        }
        
        return res;
    }
    
};