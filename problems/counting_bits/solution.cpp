/*
n = 5
0 1 2 3 4 5 6
0 1 1 2 1 2 

3: 11
4: 100
5: 101
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; ++i) {
            int cnt = popCnt(i);
            res[i] = cnt;
        };
        return res;
    }

    int popCnt(int n) {
        int cnt = 0;
        while (n > 0) {
            n &= (n - 1);
            ++cnt;
        }
        return cnt;
    }
};