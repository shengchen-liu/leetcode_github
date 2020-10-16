/*
1,1,1,2,2,3

min heap
1: 1
1: 2
1: 3
2: 1, 1: 3
2: 2, 1: 3
3: 1, 2: 2, 1: 3 size > k => pop the top 
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        
        // pq
        for (auto it : m) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};