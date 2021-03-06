class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[1] - a[0] == b[1] - b[0]) {
            return a[0] < b[0];
        }
        return a[1] - a[0] < b[1] - b[0];
    }
    
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        /*
        for (int i = 0; i < tasks.size(); ++i) {
            cout << "(" << tasks[i][0] << " " << tasks[i][1] << ")";
        }
        */
        int res = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            res += tasks[i][0];
            res = max(res, tasks[i][1]);
        }
        return res;
    }
};