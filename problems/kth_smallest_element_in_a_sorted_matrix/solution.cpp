// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int> q;
//         int n = matrix.size();
//         // insert all values into the heap
//         // pop the largest element if the heap's size exceeds k
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 q.push(matrix[i][j]);
//                 if (q.size() > k) {
//                     q.pop();
//                 }
//             }
//         }
//         return q.top();
        
//     }
// };

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        typedef pair<int, int> Pii;
        typedef pair<int, Pii> ElemType;    // 放入堆的元素要记录值和它的坐标
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<ElemType, vector<ElemType>, greater<ElemType>> heap;
        
        vis[0][0] = 1;
        heap.push(ElemType(matrix[0][0], Pii(0, 0)));
        
        for (int i = 1; i < k; i++)
        {
            ElemType t = heap.top();
            heap.pop();
            
            int x = t.second.first;
            int y = t.second.second;
            
            if (x + 1 < n && !vis[x+1][y])
            {
                heap.push(ElemType(matrix[x+1][y], Pii(x+1, y)));
                vis[x+1][y] = 1;
            }
            
            if (y + 1 < m && !vis[x][y+1])
            {
                heap.push(ElemType(matrix[x][y+1], Pii(x, y+1)));
                vis[x][y+1] = 1;
            }
        }
        
        return heap.top().first;
    }
};