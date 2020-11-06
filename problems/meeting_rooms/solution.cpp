/*
[[0,30],[5,10],[15,20]]
1. sort by starting time
[0,30],[5,10],[15,20]
iterate all meetings:
    check cur_end <= nex_start 
*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return true;
        
        // 1. sort
        sort(intervals.begin(), intervals.end());
        
        // 2. iterate
        for (int i = 0; i < intervals.size() - 1; ++i) {
            int cur_end = intervals[i][1];
            int next_start = intervals[i + 1][0];
            if (cur_end > next_start) return false;
        }
        
        return true;
    }
};