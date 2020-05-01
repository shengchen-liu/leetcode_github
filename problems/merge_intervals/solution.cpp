/*
1. sort intervals by starting point
2. for each interval i:
    for j = i + 1 to n
        if i.end >= j.start : merge
        else : push interval i to res, break
    
*/

class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]); // [1, 3]
        for (int i = 0; i < n; ++i) {
            if (res.back()[1] < intervals[i][0]) res.push_back(intervals[i]);
            else{
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};