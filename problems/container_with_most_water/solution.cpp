/**
p1, p2
maxArea;
compute maxArea based on p1, p2
move the shorter one among p1, p2, update maxArea
**/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int p1 = 0;
        int p2 = n -1;
        int maxArea = (p2 - p1) * min(height[p1], height[p2]);
        
        while (p1 < p2) {
            if (height[p1] <= height[p2]) {
                ++p1;
            } else {
                --p2;
            }
            int temp = (p2 - p1) * min(height[p1], height[p2]);
            maxArea = temp > maxArea ? temp : maxArea;
        }
        return maxArea;
    }
};