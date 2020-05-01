class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end());
        int res = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= end) { // covered
                end = min(points[i][1], end);
            } else {
                ++res;
                end = points[i][1];
            }
        }
        return res;
    }
};