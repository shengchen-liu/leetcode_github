class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int res = 0;
        int l = 0;
        int r = n - 1;
        int max_l = height[0];
        int max_r = height[n - 1];
        while (l < r) {
            if (max_l < max_r) {
                res += max_l - height[l];
                max_l = max(max_l, height[++l]);
            } else {
                res += max_r - height[r];
                max_r = max(max_r, height[--r]);
            }
        }
        return res;
    }
};