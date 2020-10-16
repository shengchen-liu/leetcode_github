/*
topological sort
[[1,0], [0, 2], [3, 2], [3, 4]]

0 -> 1
2 -> 0
2 -> 3
4 -> 3

build a in-dgree graph
1: 1
0: 1
3: 2
2: 0
4: 0

BFS:
start with in-dgree == 0 nodes
update in-dgree graph when a node is visited

end of loop
compare count == n?
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        unordered_map<int, vector<int>> m;
        // in-degree graph
        for (auto a : prerequisites){
            int first = a[0];
            int second = a[1];
            in_degree[first]++;
            m[second].push_back(first);
        }
        
        // bfs
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) q.push(i);
        }
        
        // q: {2, 4}
        int cnt = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ++cnt;
            // find all neighbors that cur points to
            for (int i : m[cur]) {
                --in_degree[i];
                if (in_degree[i] == 0)
                    q.push(i);
            }
        }
        return cnt == numCourses;
        
    }
};