/*
sort edges from small distance to large distance
traverse the queries from small limit ot large limit.
Given a limit, we union all the nodes that can be connected
In this way, we need to traverse the edges that are smaller than the limit.  We just need to visit the edges once from small distance to large distance.

n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]

1. sort edges
edgeList:
[0,1,2],
[1,2,4],
[2,0,8],
[1,0,16]

2. sort queries from small limit to large limit
[0,1,2],
[0,2,5]

3. for each limit in quereies, union edges 
limit: 2
[]

limit: 5
[0,1,2]

*/
class UnionFind{
public:
    UnionFind(int n) {
        father.resize(n);
        for (int i = 0; i < n; ++i) 
            father[i] = i;
    }
    int find(int x) {
        if (x == father[x])
            return x;
        return father[x] = find(father[x]);
    }
    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
        }
    }
    bool connected(int x, int y) {
        int fx = find(x);
        int fy = find(y); 
        return fx == fy;
    }
    
private:
    vector<int> father;
};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) 
            queries[i].push_back(i);
        
        // 1. sort edges
        sort(edgeList.begin(), edgeList.end(), [](const vector<int> &e1, const vector<int> &e2){ return e1[2] < e2[2];});
        
        // 2. sort queries
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int> &b) {return a[2] < b[2];});
        
        UnionFind uf(n);
        
        // 3. traverse each query
        int j = 0; // cnt in edges
        for (int i = 0; i < queries.size(); ++i) { // q: vector<int>
            auto q = queries[i];
            // union
            int a = q[0];
            int b = q[1];
            int limit = q[2];
            while (j < edgeList.size()) {
                auto e = edgeList[j];
                int x = e[0];
                int y = e[1];
                int dis = e[2];
                if (dis >= limit)
                    break;
                uf.merge(x, y); // connect these two noeds
                ++j;
            }
            res[q[3]] = uf.connected(a, b);
        }
        return res;
    }
};