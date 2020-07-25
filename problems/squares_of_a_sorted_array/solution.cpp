class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int n = A.size();
        
        int a = 0;
        // find the first value >= 0
        for (int i = 0; i < n; ++i) {
            if (A[i] >= 0) {
                a = i;
                break;
            }
        }
                
        int b = a - 1; // largest negative index
        while (a < n && b >= 0) {
            if (abs(A[a]) <= abs(A[b])) {
                res.push_back(A[a] * A[a]);
                ++a;
            } else {
                res.push_back(A[b] * A[b]);
                --b;
            }
        }
        
        // anything remaining?
        while (a < n) {
            res.push_back(A[a] * A[a]);
            ++a;
        }
        
        while (b >= 0){
            res.push_back(A[b] * A[b]);
            --b;
        }
        
        return res;
    }
};