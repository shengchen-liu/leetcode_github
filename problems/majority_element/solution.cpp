/*
[2,2,1,1,1,2,2] n=7
2: 4
1: 3

*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                res = num;
                ++cnt;
            } else if (num == res) ++cnt;
            else --cnt;
        }
        return res;
    }
};