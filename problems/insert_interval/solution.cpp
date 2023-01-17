/*
[1,3],[6,9]

1 2 3 4 5 6 7 8 9 10
- - -     - - - -
  x x x x

- - - - -
          - - - -


find overlapping regions
for each interval:
    1) ei <= s* : no overlap.  keep interval i
    2) si >= e* : no overlap, keep interval
    3) others:  s = min(si, s*); e = max(ei, e*)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int cur = 0;  // location to insert the new interval
        for (auto interval : intervals) {
          int si = interval[0];
          int ei = interval[1];
          if (ei < newInterval[0]) {
            res.push_back(interval);
            ++cur;
          } else if (si > newInterval[1]){
            res.push_back(interval);
          } else {
            newInterval[0] = min(si, newInterval[0]);
            newInterval[1] = max(ei, newInterval[1]);
          }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};