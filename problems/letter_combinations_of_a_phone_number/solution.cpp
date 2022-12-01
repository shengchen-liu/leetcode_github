/*
23
2: a,b,c
3: d,e,f
...
9: w,x,y,z

ad,ae,af,bd,be,bf,cd,ce,cf

1. hashmap: digit : letters
2. search dfs

dfs(start, path, res, digits)
// termination
if start == digits.end:
    res += path
    return
// recursion
for each candi i from hashmap[digit]:
    path.push_back(i)
    dfs(start + 1, path, res, digits)
    path.pop_out()

*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string path;
        // hashmap
        unordered_map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";

        if (digits == "")
        return {};
        
        dfs(0, path, res, digits, m);
        return res;
    }

    void dfs(int start, string path, vector<string>& res, const string& digits, unordered_map<int, string>& m) {
        // terminaiton
        if (start == digits.size()) {
            res.push_back(path);
            return;
        }

        // recursion
        int cur = digits[start] - '0';  // 2
        for (char digit : m[cur]) {
            dfs(start + 1, path + digit, res, digits, m);
        }
    }
};