class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // sort
        vector<int> tmp = {a, b, c};
        sort(tmp.begin(), tmp.end());
        int res = 0;
        if (tmp[0] + tmp[1] <= tmp[2]) {
            res = tmp[0] + tmp[1];
        } else {
            res = tmp[0] + tmp[1] + tmp[2];
            res = res / 2;
        }
        return res;
    }
};