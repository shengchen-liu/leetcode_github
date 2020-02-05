class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int res = INT_MAX;
        unordered_map<int, vector<vector<int>>> hashmap;
        // map: {index: {index, price}}
        for (auto flight : flights) {
           hashmap[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<vector<int>> q;
        q.push({src, 0});
        int count = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto temp = q.front(); // {0, 0}
                q.pop();
                // neighbors
                if (temp[0] == dst) res = min(res, temp[1]);
                for (auto neighbor : hashmap[temp[0]]) {// {1, 100}
                    if (temp[1] + neighbor[1] > res) continue;
                    q.push({neighbor[0], temp[1] + neighbor[1]});
                }
            }
            if (count > K) break;
            ++count;
        }
        return (res == INT_MAX) ? -1 : res;
        
    }
};