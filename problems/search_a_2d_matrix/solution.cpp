class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m * n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) start = mid;
            else end = mid;
        }
        if (matrix[start / n][start % n] == target) return true;
        if (matrix[end / n][end % n] == target) return true;
        return false;
    }
};