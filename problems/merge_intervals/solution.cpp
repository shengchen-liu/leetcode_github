/*
sort by starting point

*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        vector<vector<int>> res;
        int n = intervals.size();
        // sort
        auto cmp = [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        };
        
        sort(intervals.begin(), intervals.end(), cmp);
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