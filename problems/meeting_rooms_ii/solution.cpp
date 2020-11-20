class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<vector<int>> points;
        for (int i = 0; i < intervals.size(); ++i) {
            points.push_back({intervals[i][0], 1});
            points.push_back({intervals[i][1], -1});
        }
        
        // sort
        sort(points.begin(), points.end());
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][1] == 1) {
                ++cnt;
            }
            else 
                --cnt;
            res = max(res, cnt);
        }
        return res;
    }
};