/*
1. sort by start point
2. count num of layers

*/
class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), comp);
        
        //count num of layers
        int cnt = 0;
        int tail = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; ++i) {
            if (tail <= intervals[i][0]) tail = intervals[i][1];
            else {
                ++cnt;
                tail = min(tail, intervals[i][1]);
            }
        }
        return cnt;
    }
};