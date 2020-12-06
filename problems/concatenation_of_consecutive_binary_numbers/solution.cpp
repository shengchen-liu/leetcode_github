/*
n. return decimal value of binary string 
n = 3
1. 1 to n : 1, 2, 3
1: 1
2: 10
3: 11
"1" + "10" + "11" -> "11011"

2. convert binary string -> decimal int
"11011" -> 27(dec)

n = 4
1, 2, 3, 4
1: 1
2: 10
3: 11
4: 100

"1" + "10" + "11" + "100" -> "11011" + "100" => "11011100" => 220
1. 11011 000
2. 11011000 + 100 => 11011100
dp[i]: decimal val of concateded binary from 1 to i
vs. dp[i-1]
dp[i] = dp[i-1] << positions + i

initial: 
dp[1] = 1

optimization: 
 res = ((res << pos) + i) % (10^9 + 7)
    
i-1: 0111
i:   1000
&:   0000


*/
class Solution {
public:
    int concatenatedBinary(int n) {
        int size = 0; 
        long res = 0;
        // itera
        for (int i = 1; i <= n; ++i) {
            // detemine size to be shifted
            if (!(i & (i - 1))) { // i: 2
                ++size;
            }
            res = ((res << size) | i) % (1000000007);
            // res = (res << size) | i;
            // cout << res << endl;
        }
        return  res;
    }
};