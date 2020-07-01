/*
max heap: sort by distance
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        auto cmp = [](vector<int> &p1, vector<int> &p2) {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < points.size(); ++i) {
            if (pq.size() < K) pq.push(points[i]);
            else if (distance(pq.top()) > distance(points[i])) {
                pq.pop();
                pq.push(points[i]);
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
    
    int distance(vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
};