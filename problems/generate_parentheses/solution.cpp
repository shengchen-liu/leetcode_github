/*
N = 3
dfs
observatation:
1. idx '0' must be (   
2.diff = num_right_rem - num_left_rem
diff must >= 0 to be valid
                                     left_remain    right_remain
                       (              2             3 
                     {2, 3}                     
                     (      )  
                   {1,3}   {2,2}
                   (   )      (     )
                {0,3} {1,2} {1,2} {2,1}
                   ) (  )
                   )
                   )
...
                )
                {0,0}

string dfs(int left, int right, vector<string>& res)
    if diff >= 0:
        dfs(left-1, right, diff, res)
        dfs(left, right-1, diff, res)
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, res, "");
        return res;
        
    }
    
    void dfs(int left_rem, int right_rem, vector<string>& res, string path) {
        // termination
        if (left_rem == 0 && right_rem == 0){
            res.push_back(path);
            return;
        }
        
        int diff = right_rem - left_rem; // >=0
        if (diff < 0) return;
        
        // recursion
        if (left_rem > 0)
            dfs(left_rem - 1, right_rem, res, path + "(");
        if (right_rem > 0)
            dfs(left_rem, right_rem - 1, res, path + ")");
    }
};