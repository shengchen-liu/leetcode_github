class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        // 123
        while (x != 0) {
            int pop = x % 10; // 3
            x /= 10; //12
            if (rev)
            // check overflow
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;// 214748364 + 7
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop; // 3
        }
        return rev;
    }
};