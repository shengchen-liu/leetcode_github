/*
[0,10],[5,10],[15,20], [15,30]
1. sort by start
0  5  10  15  20  25  30                          heap
0  0  0                                           10
   1  1                                           10,10
          0   0                                   15,20
          1   1   1   1                                         
front's end vs behind's end

heap: 
20, 30, 30 

5 vs 30 -> overlap  => rooms = 2
insert 10

15 vs 10  -> no overlap => rooms = 2
pop
inset 20

15 vs 20  -> overlap => room++ =  3 
for each interval:
    compare start vs. earliest ending time
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort by start
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;  // min heap
        int cnt = 0;
        for (auto interval : intervals) {
            if (pq.empty() || interval[0] < pq.top()) {
                pq.push(interval[1]);
                ++cnt;
            } else {
                pq.pop();
                pq.push(interval[1]);
            }
        }
        return cnt;
    }
};