/*
S="abcdebdde", T = "bde"
W is substring of S.
T is a subsequence of W. No need to be congiguous
W minimum
S = a[bcde]bdde
2Tasks.
Task1: find W from S.  Substring problem
    sliding window, 2 ptrs i, j
Task2: T is subsequence of W.
T = "bbde"
hashmap:
b: 2
d: 1
e: 1
W must contain all occurs in hashmap

remaining hashmap

(1)
S[i] not in hashmap:
    ++i
else: (S[i] in hashmap)
    current[S[i]]--
    if (current[S[i]] < map[S[i]]):
        --cnt
(2)
cnt = 0
S[j] not in map:
    ++j
S[j] in map:
    update current
    if curr[S[j]] == map[S[j]]:
       ++cnt
    if cnt == T.size()
        update min_len = min(min_len, j - i + 1)
        update res
        update i
        
    
find all windows         
idx:  0 1 2 3 4 5 6 7 8      current             cnt
      a b c d e b d d b
      ij
        ij                   b:1                  1
        i j                  b:1                  1
        i   j                b:1, d:1             2
        i     j              b:1, d:1, e:1        2 
        i       j            b:2, d:1, e:1        3*         bcdeb
            i    j            b:1, d:1, e:1        2
            i      j          b:1, d:2, e:1        2
            i        j        b:1, d:3, e:1        2
            i          2      b:2, d:3, e:1        3      8 - 3 + 1=6 > 5
        
*/
class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX, i = 0, j = 0;
        while (i < m) {
            if (S[i] == T[j]) {
                if (++j == n) {
                    int end = i + 1;
                    while (--j >= 0) {
                        while (S[i--] != T[j]);
                    }
                    ++i; ++j;
                    if (end - i < minLen) {
                        minLen = end - i;
                        start = i;
                    }
                }
            }
            ++i;
        }
        return (start != -1) ? S.substr(start, minLen) : "";
    }
};