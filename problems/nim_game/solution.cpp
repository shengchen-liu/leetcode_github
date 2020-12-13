/*
n = 4
              4(F)
      /-1      |-2     \-3
     3(T)     2(T)       1(T) 
/-1  |-2  \-3
2    1     0(F)
     
dp[i]: if I can win if there are i stones remaining
dp[i] = !dp[i-1] && !dp[i-2] && !dp[i-3]
initial
dp[0] = F
dp[1] = t
dp[2] = t
dp[3] = t
*/
class Solution {
public:
    bool canWinNim(int n) {
return n % 4 != 0;
    }
};