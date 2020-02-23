class Solution {
public:
    int find(vector<int> &root, int i) {
        while (root[i] != i) i = root[i];
        return i;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (auto a : edges) {
            int x = find(root, a[0]), y = find(root, a[1]);
            if (x != y) {
                --res;
                root[y] = x;
            }
        }
        return res;        
    }
};