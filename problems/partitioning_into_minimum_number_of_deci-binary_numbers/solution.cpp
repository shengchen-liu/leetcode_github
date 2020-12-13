/*
n = 32
32 = 3 * 10 + 2 * 1

n = 82734
82734 = 8 * 10000 + 2 * 1000 + 7*100 + 3 * 10 + 4*1

n = 27346209830709182346

find largest digit
*/


class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (char c : n) {
            res = max(res, c - '0');
        }
        return res;
    }
};