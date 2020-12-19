/*
s
return num of unque chars

t: a substring of s
return sum of uniqueChars for all t

ABC
substrings: 3 + 2 + 1
A, 1 
B, 1
C  1
AB, 2
BC  2
ABC 3

ABA
A: 1
B: 1
A: 1
AB: 2
BA: 2
ABA: 1

find all substring
size : n
in total: n + (n - 1) + (n - 2) + ... + 1

   0 1 2 
0  1 2 1
1    1 2
2      1

dp[0][1]
dp[i][j] : # of unique chars for substr i to j
for each i from 0 to n-1:
    dp[i][i] = 1

vector size of 26
hashmapt
A : 1 
B : 1
dp[1][1]
dp[0][1]
dp[1][2]: 2
dp[0][2]: 1

j from 0 to n-1:
    initial hashmap
    i from j to 0
    dp[i][j]:
        if s[j] is 1st time we see => dp[i][j] = dp[i + 1][j] + 1
        else: 1) s[j] appears once before => dp[i][j] = dp[i + 1][j] -1;
              2) s[j] appears more thant once before => dp[i][j] = dp[i + 1][j]
        update hashmap

       i       j
* * * [* * ... * ] * * *
*/
class Solution {
public:
    int uniqueLetterString(string s) {
        int res = 0, n = s.size(), M = 1e9 + 7;
        vector<vector<int>> idx(26, vector<int>(2, -1));
        for (int i = 0; i < n; ++i) {
        	int c = s[i] - 'A';
        	res = (res + (i - idx[c][1]) * (idx[c][1] - idx[c][0]) % M) % M;
        	idx[c][0] = idx[c][1];
        	idx[c][1] = i;
        }
        for (int c = 0; c < 26; ++c) {
        	res = (res + (n - idx[c][1]) * (idx[c][1] - idx[c][0]) % M) % M;
        }
        return res;
        
    }
};