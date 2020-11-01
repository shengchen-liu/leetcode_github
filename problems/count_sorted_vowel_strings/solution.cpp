/*
"a","e","i","o","u"
n = 1
s = a, e, i, o, u

n = 2
s = aa, ae, ai, ao, au, ee, ei, eo, eu, ii, io, iu, oo, ou, uu => 5 + 4 + 3 + 2 + 1 = 15

n = 3
s = aaa, aae, aai,.., aau
    ae
dfs
supposer at idx i, the letter is kth in vowels.
for i = 0 : n
    for k = 0 : 4
        f(i - 1, k) * (5 - k) 
f[n-1, 0] + f[n-1, 1] +... +
*/
class Solution {
public:
    int countVowelStrings(int n) {
        int sum = 0;
        return helper(0, 0, n);
    }
    
    // at current layer, parent is pre => return total # of combinatinos
    int helper(int layer, int pre, int n) {
        // termination
        if (layer == n) return 1;
        
        // recursion
        int sum = 0;
        for (int i = pre; i < 5; ++i) {
            sum += helper(layer + 1, i, n);
        }
        return sum;
    }
};