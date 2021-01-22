/*
0  1  2  3  4  5
1, 2, 3, 1, 1, 3

1: 0, 3, 4 => 3
2: 1
3: 1, 2 => 1

i : k => 1 + 2 + ... + (k - 1) = k * (k - 1) / 2

*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int x : nums) {
            m[x]++;
        }
        int res = 0;
        for (int i = 1; i <= 100; ++i) {
            if (m.count(i)) {
                int tmp = m[i];
                res += tmp * (tmp - 1) / 2;
            }
        }
        return res;
    }
};