class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // start from bottom left
        int row = m - 1;
        int col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] < target)
                ++col;
            else 
                --row;
        }
        return false;
    }
};