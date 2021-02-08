/*
0 0 0 1
0 1 0 0 = 
0 1 0 1

x ^ y = z
cnt # of 1s in z
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int z = x ^ y;
        // cnt
        while (z > 0) {
            int digit = z & 1;
            if (digit == 1)
                ++res;
            z = z >> 1;
        }
        return res;
    }
};