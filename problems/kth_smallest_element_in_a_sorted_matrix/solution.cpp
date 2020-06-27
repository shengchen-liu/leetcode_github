/*
max heap with size of k
[1]
[5, 1]
[9, 5, 1]
[13, 13, 12, 11, 10, 8, 5, 1]
[]

*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n; ++j) {
                if (q.size() < k) q.push(matrix[i][j]);
                else if (matrix[i][j] < q.top()) {
                    q.pop();
                    q.push(matrix[i][j]);
                }
            }
        }
        return q.top();
    }
};