class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int i = boxes.size() - 1;
        int cnt = 0;
        sort(boxes.begin(), boxes.end());
        
        for (int room : warehouse) {
            while (i >= 0 && boxes[i] > room) {
                --i;
            }
            
            if (i == -1)
                return cnt;
            
            cnt++;
            i--;
        }
        
        return cnt;
    }
};