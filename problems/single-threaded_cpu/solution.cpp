/*
[1,2],[2,4],[3,2],[4,1]
sort by processing time
[4,1],[1,2],[3,2],[2,4]

cpu is idle: 
    
*/
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // processing time, index
        int n = tasks.size();
        long time = 0;
        int i = 0;
        for (int i = 0; i < n; ++i)
            tasks[i].push_back(i); // append index
        
        // sort by the enqueue time
        sort(begin(tasks), end(tasks));
        
        vector<int> res;
        
        while (i < n || !pq.empty()) { // stop the loop if we exhausted the input array or the heap is empty
            if (pq.empty()) { // nothing in the heap
                time = max(time, (long) tasks[i][0]);
            }
            while (i < n && time >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            
            auto a = pq.top(); 
            pq.pop(); // pair<int, int>
            time += a.first;
            res.push_back(a.second);
        }
        return res;
    }
};