class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int i = 0, j = n - 1;
        while (i < j) {
            res = max(min(height[i], height[j]) * (j - i), res);
            height[i] <= height[j] ? ++i : --j;
        }
        return res;
    }
};