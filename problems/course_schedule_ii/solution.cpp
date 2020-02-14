/**
[child, parent]
**/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> res;
        // in degree
        vector<int> in_degree(numCourses, 0);
        for (auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            ++in_degree[edge[0]];
        }
        
        // BFS
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int course = q.front();
            res.push_back(course);
            q.pop();
            // q's children
            for (auto child : graph[course]) {
                --in_degree[child];
                if (in_degree[child] == 0) q.push(child);
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] != 0) return {};
        }
        return res;
        
    }
};