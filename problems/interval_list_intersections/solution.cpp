/**
A: [0, 2]
B: [1, 5]

0: 1
1: 2
2: 1
5: 0
**/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        
        while (i < A.size() && j < B.size()) {
            // check if A[i] , B[j] intersects
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            
            if (lo <= hi) {
                res.push_back({lo, hi});
            }
            
            // remove the interval with the smallest endpoint
            if (A[i][1] < B[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        
        return res;
    }
};