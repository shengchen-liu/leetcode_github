class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;
        vector<int> father(n);
        for (int i = 0; i < n; ++i) father[i] = i;
        for (auto a : edges) {
            int x = find(a[0], father);
            int y = find(a[1], father);
            if (x != y) {
                father[y] = x;
                --res;
            }
        }
        return res;
    } 
    
private:
    int find(int x, vector<int> &father) {
        while (x != father[x]) x = father[x];
        return x;
    }
};