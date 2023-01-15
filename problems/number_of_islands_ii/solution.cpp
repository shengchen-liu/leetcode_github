/*
m = 3, n = 3

0 0 0
0 0 0
0 0 0 

[0,0] => 1
1 0 0
0 0 0
0 0 0 

[0,1] => 1
1 1 0
0 0 0
0 0 0 

[1,2] => 2 
1 1 0
0 0 1
0 0 0 

union find
every operation:
build a new group[i,j]
    father({i,j}) = {i,j}
    ++cnt
for each of its 4 neighbors:
    if neighbor == 1:
        merge node's group with neighbor's group
        --cnt

return total number of groups
*/
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        int cnt = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        vector<int> roots(m * n, -1);  

        for (auto position : positions) {
            int x = position[0];
            int y = position[1];
            int idx = n * x + y;
            if (roots[idx] != -1) {
                res.push_back(cnt);
                continue;
            }
            roots[idx] = idx;
            ++cnt;
            for (int i = 0; i < 4; ++i) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                int cur_id = n * x1 + y1;
                if (x1 < 0 || x1 > m - 1 || y1 < 0 || y1 > n - 1 || roots[cur_id] == -1)
                    continue;
                merge(idx, cur_id, roots, cnt);
            }
            res.push_back(cnt);
        }
        return res;
    }

    int findRoot(vector<int>& roots, int id) {
        if (id == roots[id])
            return id;
        roots[id] = findRoot(roots, roots[id]);
        return roots[id];
    }

    void merge(int i, int j, vector<int>& roots, int& cnt) {
        int p = findRoot(roots, i);
        int q = findRoot(roots, j);
        if (p != q){
            roots[p] = q;
            --cnt;
        }
    }
};