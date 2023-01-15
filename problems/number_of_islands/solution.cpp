class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        vector<int> parents(m * n, -1);
        for (int i = 0; i < m * n; ++i) {
            parents[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0')
                    continue;
                // search neighbor
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')
                        continue;
                    merge(i * n + j, x * n + y, parents);                    
                    if (x == 1 && y == 1)
                        cout << parents[x * n + y] << endl;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m * n; ++i) {
            if(parents[i] == i && grid[i/n][i%n] == '1')
                ++res;
        }
        return res;
    }

    int find(int i, vector<int>& parents){
        if (i == parents[i])
            return i;
        return parents[i] = find(parents[i], parents);
    }
    
    void merge(int i, int j, vector<int>& parents) {
        int p1 = find(i, parents);
        int p2 = find(j, parents);
        if (p1 != p2)
            parents[p1] = p2;
    }

};