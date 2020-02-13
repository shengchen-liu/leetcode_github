class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](const vector<int>& num1, const vector<int>& num2) {return num1[0]<num2[0];});
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int n = intervals.size();
        for (int i = 1; i < n; ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max (res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
    

};