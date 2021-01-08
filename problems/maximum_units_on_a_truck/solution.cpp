class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto cmp = [](vector<int> const& p1, vector<int> const& p2){
            return p1[1] < p2[1];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto boxType : boxTypes) {
            pq.push(boxType);
        }
        
        int cnt = 0;
        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            int boxCount = min(truckSize, top[0]);
            cnt += boxCount * top[1];
            truckSize -= boxCount;
            if (truckSize == 0)
                break;
        }
        return cnt;
        
    }
};