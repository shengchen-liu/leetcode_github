/*
n = 4, k = 17
section
0  1234
1  1243
2  1324
3  1342
4  1423
5  1432

6  2134
7  2143
8  2314
9  2341
10 2413
11 2431

12 3124 0
13 3142 1

14 3214 2
15 3241 3

16 3412 4
17 3421 5

18 4123
4132
4213
4231
4312
4321

1.
first digit:= 1 => rank: 1, 2 < 3
if first digit:= 1 => range [0, 1] [0, (n-1)!]   
              := 2 =>       [2, 3] [(n - 1)!, 2(n-1)!] *
              := 3 =>       [4, 5] [2(n-1)!, 3(n-1)!]
classify all perumutation based on 1st digit.  See which section the kth falls into
which section? 
k = k -1
a1 = k / (n-1)! 16 / 3! = 16 / 6 = 2

2. inside this section, we need to dig deeper
divide based on 2nd digit
3?**

0 3124 
1 3142

2 3214
3 3241

4 3412 
5 3421
which section the k' falls into?
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
        --k;
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};