/*
[0, 1]
1->0
[0,1], [0, 2], [2, 3], [3, 4]
hashmap: parent: vector<child>
1: 0
2: 0
3: 2
4: 3

in_degree:
0: 2
1: 0
2: 1
3: 1
4: 0

cnt:=0
BFS

start with in_dgree==0 node:
    for child in m[node]:
        --in_degree[child]
        if (in_degree[child] == 0) queue.push(child), ++cnt
        
check cnt == numCourses
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> in_degree(numCourses, 0);
        
        // build hashmap. update in_degree
        unordered_map<int, vector<int>> m;
        for (auto a : prerequisites) {
            int child = a[0];
            int parent = a[1];
            m[parent].push_back(child);
            ++in_degree[child];
        }
        
        // BFS
        int cnt = 0;
        // initialize queue
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0){
               q.push(i);
            }
        }
        
        // while !q.empty
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ++cnt;
            // cur's childs
            for (int child : m[cur]) {
                --in_degree[child];
                if (in_degree[child] == 0){
                    q.push(child);
                }
            }
        }
        
        return cnt == numCourses;
    }
};