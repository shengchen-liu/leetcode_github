/**
heap:
[2,7,4,1,8,1]
max_heap[8, 7, 4, 2, 1, 1]
8, 7 => 1
[4, 2, 1, 1, 1]
4, 2 => 2
[2, 1, 1, 1]
2, 1 => 1
[1, 1, 1, 1]
1, 1 => 
[1, 1]
1, 1 => 
[0]
**/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int res = 0;
        for (int s : stones) {
            pq.push(s);
        }
        
        while (!pq.empty()) {
            int y = pq.top();
            pq.pop();
            if (pq.empty()) {
                res = y;
                break;
            }
            int x = pq.top();
            pq.pop();
            int diff = y - x;
            if (diff > 0) {
                pq.push(diff);
            }
        }
        
        // pq.size() == 0 or 1
        return res;
        
    }
};