class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int mod = 1e9 + 7;
        unordered_map<int, int> m;
        long res = 0;
        for (int x : deliciousness) {
            for (int t = 1; t <= 1 << 21; t <<= 1) {
                if (m.count(t - x))
                    res += m[t - x];
            }
            ++m[x];
        }
        return res % mod;
    }
};