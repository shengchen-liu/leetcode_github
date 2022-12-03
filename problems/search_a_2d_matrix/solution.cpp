/*
1 3 5 7
10 11 16 20
23 30 34 60

target: 3
m*n = 12
mid = mat[5] = 10 > 3
end = mid

mid = mat[2] = 5 > 3
end = mid

mid =  mat[1] = 3 == 3*
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m * n - 1;
        int i = 0;
        int j = 0;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            i = mid / n;
            j = mid % n;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) start = mid;
            else end = mid;
        }

        if (matrix[start/n][start%n] == target)
            return true;
        if (matrix[end/n][end%n] == target)
            return true;
        return false;
    }
};


