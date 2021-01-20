/*
[x1,x2,...,xn,y1,y2,...,yn] -> [x1, y1, x2, y2, ..., xn, yn]
 i            j
    i            j
*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int i = 0;
        int j = n;
        while (i < n) {
            res.push_back(nums[i++]);
            res.push_back(nums[j++]);
        }
        return res;
    }
};