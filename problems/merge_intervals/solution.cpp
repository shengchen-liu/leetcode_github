class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if (n == 1)
            return intervals;

        // sort by start
        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]); // [1,3]
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] > res.back()[1]){
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};