class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int n = light.size();
        int right = 0; // the right most bulb that is light up
        for (int i = 0; i < n; ++i) {
            right = max(right, light[i]);
            if (right == i + 1) {
                ++res;
            }
        }
        return res;
    }
};