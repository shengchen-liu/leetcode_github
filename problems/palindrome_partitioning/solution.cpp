/*
aab

max length
1 letter:
a
a
b

2 letters:
aa, b

3 letters:

palindrome: forward == reversed
every substring

a _ a  _ b
insert sperations, choose yes or no
search problem.  DFS

              aabb
        a| /          \ aa,bb
       [a, a _b_b]          [aa, b_b] 
    a,a|b_b/  \ a,ab_b        aa,b|/   \aa,bb|
  (a,a,b)_b    a,ab,b_b     [aa,b,b]*    [aa,bb]*

dfs(start, curStr, path): start at current letter, find all possible palindrome partiiton
// termination
if start == s.end:
    update res with path
    return

// recursion
for each cand i from start to end:
    curStr = s[start...i]
    if curStr is not a palindrome:
        continue
    path += curStr
    dfs(i + 1, curStr, path)
    path.pop_out


time complexity O(n * 2^n)
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        string curStr;
        vector<string> path;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n)); // dp[i][j] : s[i...j] is a palindrome?
        dfs(0, s, curStr, path, res, dp);
        return res;
    }

    void dfs(int start, const string s, string& curStr, vector<string>& path, vector<vector<string>>& res, vector<vector<bool>>& dp) {
        // termination
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        // recursion
        for (int i = start; i < s.size(); ++i) {
            curStr = s.substr(start, i - start + 1);
            // check if it is a palindrome
            if (s[i] == s[start] && ((i - start <= 2) || dp[start + 1][i - 1])) {
                dp[start][i] = true;
                path.push_back(curStr);
                dfs(i + 1, s, curStr, path, res, dp);
                path.pop_back();
            }

        }
    }


};