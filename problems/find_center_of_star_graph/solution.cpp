class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;
        for (auto edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            m[n1]++;
            m[n2]++;
            if (m[n1] > 1)
                return n1;
            if (m[n2] > 1)
                return n2;
        }
        return 0;
    }
};