/*
input + output = 111....11 in binary format

*/
class Solution {
public:
    int bitwiseComplement(int N) {
                int X = 1;
        while (N > X) X = X * 2 + 1;
        return N ^ X;
    }
};