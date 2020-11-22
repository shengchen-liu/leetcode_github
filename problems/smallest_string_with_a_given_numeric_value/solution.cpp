/*
n=3, k = 27
len: 3, num_val = 27
a: 1
b: 2
c: 3
...
z: 26
n = 3

1.
v1, v2, v3
2.
v1 <= v2 <= v3

lower: 1 
upper: 26

3.
at current posi i 
dfs(i, lower, n, k, s): 
    // termination
    if n == 0:
        if k == 0:
            return true
        else 
            return false
            
    for cand in [lower, uppeer]:
        s[i].append(cand)
        dfs(i + 1, cand, n - 1, k - cand)
        s.pop(back)
*/
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        // dfs(i, lower, upper, n, k, s)
        dfs(1, 26, n, k, res);
        return res;
    }
    
    bool dfs(int lower, int upper, int n, int k, string& res) {
        // termination
        if (n == 0) {
            if (k == 0)
                return true;
            return false;
        }
        
        // recursion
        // check boundary
        if (k < lower * n || k > upper * n)
            return false;
        
        // for each cand
        for (int cand = lower; cand <= upper; ++cand) {
            res.push_back('a' + cand - 1);
            bool tmp = dfs(cand, upper, n - 1, k - cand, res);
            if (tmp){
                return true;
            }
            else {
                res.pop_back();
            }
        }
        return false;
    }
};