class Solution {
public:
    int arraySign(vector<int>& nums) {
        double product = 1;
        for (int num : nums) {
            product *= num;
        }
        int res = 0;
        if (product > 0){
            res = 1;
        } else if (product < 0) {
            res = -1;
        } else {
            res = 0;
        }
        
        return res;
    }
};