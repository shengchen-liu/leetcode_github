class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses); // initial as zeros [0,0,0,...,0]
        vector<vector<int>> graph(numCourses);

        for(vector edge : prerequisites){
            in_degree[edge[0]]++;
            graph[edge[1]].push_back(edge[0]);
        }
        //[0, 1, ...,]
        
        //initialize a queue
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }
        //[0]
        
        // Build a 2-d vector or map
        //[[1],
        // []]
        
//         vector<vector<int>> graph(numCourses);
//         for (vector edge : prerequisites){
//             graph[edge[1]].push_back(edge[0]);
//         }
        
        vector<int> result;
        int count = 0;
        while(!q.empty()){
            int root = q.front(); // root : 0
            q.pop();
            result.push_back(root); //[0]
            count++;
            for (int child: graph[root]){
                in_degree[child]--;
                if(in_degree[child] == 0) q.push(child);
            }
        }
        if(count!=numCourses){
            result.clear();
        }
        return result;
    }
};