/*
A = [4,5,0,-2,-3,1], K = 5
4,  5,  0,  -2,  -3,  1     sum  valid?
i,j                         4     F                    
i   j                       9     F
i,      j,                  9     F
i,          j               7     F
i,               j          4     F
i                     j     5     T         1
   i,j                      5     T
   
prefix sum:
idx: 0, 1, 2, 3, 4, 5 
     4, 5, 0,-2, -3,1
sum  4, 9, 9, 7, 4, 5

sum[i~j]:= pre_sum[j] - pre_sum[i]
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, res= 0;
        for (int a : A) {
            prefix = (prefix + a % K + K) % K;
            res += count[prefix]++;
        }
        return res;
    }
};