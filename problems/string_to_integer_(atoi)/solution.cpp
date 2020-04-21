/*
1. discard whitespace
2. plus/minus sign
*/
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1;
        int res = 0;
        while (i < str.size() && str[i] == ' ') ++i;
        // plus/minus sign
        if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        else if (str[i] == '+') {
            sign = 1;
            ++i;
        }
        while (i < str.size()) {
            int digit = str[i] - '0';
            if (digit < 0 || digit > 9) break;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            ++i;
        }

        return res * sign;
    }
};