class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 1;
        for (int i = 2; i < sqrt(2 * N); ++i) {
            if ((N - i * (i - 1) / 2) % i == 0) ++res;
        }
        return res;
    }
};