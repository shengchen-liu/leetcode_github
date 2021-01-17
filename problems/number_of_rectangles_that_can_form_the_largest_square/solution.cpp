class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = 0;
        // find maxLen
        int max_len = 0;
        for (auto r : rectangles) {
            int a = r[0];
            int b = r[1];
            int len = min(a, b);
            max_len =  max(max_len, len);
        }
        
        // cnt
        for (auto r : rectangles) {
            int a = r[0];
            int b = r[1];
            if (min(a, b) == max_len)
                ++res;
        }
        
        return res;
    }
};