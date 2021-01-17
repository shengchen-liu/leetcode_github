class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        // sort
        unordered_map<int, int> m;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = nums[i] * nums[j];
                m[tmp]++;
            }
        }
        
        // c(m, 2)
        int res = 0;
        for (auto a : m) {
            int target = a.first;
            int cnt = a.second;
            if (cnt < 2)
                continue;
            int tmp = cnt * (cnt - 1) / 2;
            res += tmp;
        }
        return res * 8;
    }
};