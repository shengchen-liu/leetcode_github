class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        vector<int> res = digits;
        
        for (int i = n - 1; i >= 0; --i) {
            if (res[i] == 9) {
                res[i] = 0;
            } else {
                res[i]++;
                return res;
            }
        }
        
        vector<int> res1(n + 1, 0);
        res1[0] = 1;
        return res1;
    }
};