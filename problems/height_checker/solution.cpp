/*
0  1  2  3  4  5
1, 1, 4, 2, 1, 3

target:
1, 1, 1, 2, 3, 4

5, 1, 2, 3, 4
1, 2, 3, 4, 5

*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // sort 
        vector<int> tmp = heights;
        sort(tmp.begin(), tmp.end());
        
        // compare each pos
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != tmp[i])
                ++res;
        }
        return res;
    }
};