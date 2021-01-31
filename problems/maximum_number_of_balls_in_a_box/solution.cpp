class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;
        unordered_map<int, int> m;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int digit_sum = 0;
            int j = i;
            while (j > 0) {
                digit_sum += j % 10;
                j = j / 10;
            }
            m[digit_sum]++;
            res = max(res, m[digit_sum]);
        }
        return res;
    }
};