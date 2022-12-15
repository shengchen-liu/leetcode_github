/*
[[0,30],[5,10],[15,20]]

0   5    10    15     20     30
------------------------------
    ------
                ------ 

1. sort rooms by start time in ascending order
2. rooms: [0,30] store rooms in a min-heap sorted by end time
compare: interval.start vs. ealiest end room 
1) < : create a new room 
2) >=: use this room, update its end time with interval.end 
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 1. sort
        sort(intervals.begin(), intervals.end());

        // 2. min heap
        priority_queue<int, vector<int>, greater<int>> pq;  // end time
        for (int i  = 0; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (pq.empty() || interval[0] < pq.top()) {
                pq.push(interval[1]);
            } else {
                pq.pop();
                pq.push(interval[1]);
            }
        }
        return pq.size();
    }
};