class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int exec = x ^ y; //XOR
        while (exec) {
            ++res;
            exec &= (exec - 1);
        }
        return res;
    }
};