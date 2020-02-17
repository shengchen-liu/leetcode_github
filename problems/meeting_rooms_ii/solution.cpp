// 1. TreeMap
// class Solution {
// public:
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         map<int, int> m;
//         for (auto a : intervals) {
//             ++m[a[0]];
//             --m[a[1]];
//         }
        
//         int rooms = 0;
//         int res = 0;
//         for (auto it : m) {
//             res = max(res, rooms += it.second);
//         }
//         return res;
//     }
// };

// 2.
// class Solution {
// public:
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         vector<int> starts, ends;
//         int res = 0;
//         int endpos = 0;
//         for (auto a : intervals) {
//             starts.push_back(a[0]);
//             ends.push_back(a[1]);
//         }
//         sort(starts.begin(), starts.end());
//         sort(ends.begin(), ends.end());
        
//         for (int i = 0; i < intervals.size(); ++i) {
//             if (starts[i] < ends[endpos]) ++res;
//             else ++endpos;
//         }
//         return res;
//     }
// };


// 3. heap
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort by start time
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0];});
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto it : intervals) {
            if (!q.empty() && it[0] >= q.top()) q.pop();
            q.push(it[1]);
        }
        return q.size();
    }
};