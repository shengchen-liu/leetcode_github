/*
[1950,1961],[1960,1971],[1970,1981]

1950
1960
1970
*/
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>> points;
        int n = logs.size();
        for (int i = 0; i < n; ++i) {
            points.push_back({logs[i][0], 1});
            points.push_back({logs[i][1], -1});
        }
        
        // sort
        sort(points.begin(), points.end());
        int res = points[0][0];
        int maxAlive = 0;
        int curAlive = 0;
        for (int i = 0; i < points.size(); ++i) {
            cout << points[i][0] << ", " << points[i][1] <<  endl;
            if (points[i][1] == 1) {
                ++curAlive;
                if (curAlive > maxAlive) {
                    maxAlive = curAlive;
                    res = points[i][0];
                    // cout << res << endl;
                }
            }
         else{
                --curAlive;
            }
        }
        
        return res;
    }
};