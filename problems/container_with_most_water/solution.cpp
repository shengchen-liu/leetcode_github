/*
area = max(area, j-i * min(h[i], h[j]))
    
0,1,2,3,4,5,6,7,8
1,8,6,2,5,4,8,3,7    area
i               j    8
  i             j    49
  i           j      18     
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0; 
        int j = n - 1;
        int res = 0;
        while (i < j) {
            int tmp = (j - i) * min(height[i], height[j]);
            res = max(res, tmp);
            if (height[i] > height[j])
                --j;
            else 
                ++i;
        }
        return res;
    }
};