/*
[[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
sort by deadline:
[100, 200]
[1000, 1250]
[200, 1300]
[2000, 3200]

time:
0-100 [100, 200]
100-1100 [1000, 1250]
1100-1300 [200, 1300] 
1300-3300 [2000, 3200] x
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int curTime = 0;
        priority_queue<int> q;
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
        for (auto course : courses) {
            curTime += course[0];
            q.push(course[0]);
            if (curTime > course[1]) {
                curTime -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};