class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(); // 2
        vector<vector<int>> res;
        int cur = 0; // location to insert new interval
        for (int i = 0; i < n; ++i) { // i = 0
            if(intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                ++cur;
            } else if (intervals[i][0] > newInterval[1]){
                res.push_back(intervals[i]);
            } else {
                //[min(a[0], b[0]), max(a[1], b[1])]
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};