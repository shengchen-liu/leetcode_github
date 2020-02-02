class Solution {
public:
    void dfs(int cur, int parent, int& dep, vector<vector<int>>& adjList, vector<vector<int>>& bridges, vector<int>& depth, vector<int>& lowLink, vector<bool>& visited) {
    visited[cur] = true;
    depth[cur] = lowLink[cur] = ++dep;
    
    for(auto to: adjList[cur]) {
        if(to == parent) continue;
        if(!visited[to]) {
            dfs(to, cur, dep, adjList, bridges, depth, lowLink, visited); 
            lowLink[cur] = min(lowLink[cur], lowLink[to]);
            if(depth[cur] < lowLink[to]) bridges.push_back({cur, to}); 
        } else lowLink[cur] = min(lowLink[cur], depth[to]);
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adjList(n), bridges;
    for(auto i: connections) {
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);  
    }
    vector<int> depth(n), lowLink(n);
    vector<bool> visited(n);
    int dep = 0;
    dfs(0, -1, dep, adjList, bridges, depth, lowLink, visited); // for(int i = 0; i < n; i++) if(!visited[i]) dfs(i, ...)
    return bridges;
}
};