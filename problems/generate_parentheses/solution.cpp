/*
1. # of ( == # of )
2. at position i, # of ( >= # of )
    set a cnt >= 0
n pairs
1st position: (

dfs (back tracking)
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string out;
        helper(0, n, 0, 0, res, out);
        return res;
    }
    
    // at position i, generate current string : out
    void helper(int i, 
                int n,
                int left,
                int right,
                vector<string>& res, 
                string out) {
        if (i == 2 * n) {
            res.push_back(out); // i : 0, 1
            return;
        }
        
        // out + '('
        if (left < n) {
            helper(i + 1, n, left + 1, right, res, out + '(');
        }
        // out + ')'
        if (left > right) {
            helper(i + 1, n, left, right + 1, res, out + ')');
        }
    }
};