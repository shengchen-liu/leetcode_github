class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0; // # of ( to be deleted
        int r = 0; // # of ) to be deleted
        
        for (char c : s) {
            if (c == '(')
                ++l;
            if (l == 0){
                if (c == ')')
                    ++r;
            } else {
                if (c == ')')
                    --l;
            } 
        }
        
        vector<string> res;
        dfs(s, 0, l, r, res);
        return res;
    }
    
    bool isValid(string &s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(')
                ++cnt;
            else if (c == ')')
                --cnt;
            if (cnt < 0)
                return false;
        }
        return cnt == 0;
    }
    
    void dfs(string &s, int start, int l, int r, vector<string> &res) {
        // termination
        if (l == 0 && r == 0) {
            if (isValid(s))
                res.push_back(s);
            return;
        }
        
        // recursion
        for (int i = start; i < s.size(); ++i) {
            // we only remvoe the 1st paranthes if there are consecutive ones to avoid duplication
            if (i != start && s[i] == s[i - 1])
                continue;
            
            if (s[i] == '(' || s[i] == ')') {
                string cur = s;
                cur.erase(i, 1);
                if (r > 0 && s[i] == ')')
                    dfs(cur, i, l, r - 1, res);
                else if (l > 0 && s[i] == '(')
                    dfs(cur, i, l - 1, r, res);
            }
        }
    }
};