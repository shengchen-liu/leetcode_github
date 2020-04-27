/*
n = 9
1. a1, a9 => 1 * (9 - 1) = 8
2. a2, a9 => min(a2, a9) * (9 - 2) = 7 * 7 = 49
3. 2, 8 => min(a2, a8) * (8 - 2) = 3 * 6 = 18
4. 2, 7 => min(a2, a7) * (7 - 2) = 8 * 5 =  40
...
i, j => min(ai, aj) * (j - 1), npdate res
ai >= aj ? --aj : ++ai;

while (i < j) 
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int tmp = min(height[i], height[j]) * (j - i);
            res = max(res, tmp);
            height[i] >= height[j] ? --j : ++i;
        }
        return res;
    }
};