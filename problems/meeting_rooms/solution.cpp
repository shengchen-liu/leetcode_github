class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return true;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; ++i) {
            int last_end = intervals[i][1];
            int next_start = intervals[i + 1][0];
            if (last_end > next_start) return false;
        }
        return true;
    }
};