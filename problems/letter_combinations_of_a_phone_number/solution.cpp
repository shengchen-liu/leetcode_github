/*
2, 3, 4
2: a, b, c
3: d, e, f
4: g, h ,i

0(2):          a,       b,        c
1(3):     d,         e,        f       d, e, f   d, e, f
2(4): [g, h, i] [g, h, i]  [g, h, i] ....
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        unordered_map<int, vector<char>> m;
        m[2] = {'a', 'b', 'c'};
        m[3] = {'d', 'e', 'f'};
        m[4] = {'g', 'h', 'i'};
        m[5] = {'j', 'k', 'l'};
        m[6] = {'m', 'n', 'o'};
        m[7] = {'p', 'q', 'r', 's'};
        m[8] = {'t', 'u', 'v'};
        m[9] = {'w', 'x', 'y', 'z'};
        vector<string> res;
        string path = "";
        helper(res, path, digits, 0, m);
        return res;
        
    }
    
    // at current level, constrcut combinations
    void helper(vector<string> &res, 
               string path,
                string digits,
               int level,
               unordered_map<int, vector<char>> &m) {
        // termination
        int n = digits.size();
        if (level == n) {
            res.push_back(path);
            return;
        }
        
        // recursion
        // at current level, go throught all candi
        int cur = digits[level] - '0';// 2
        vector<char> cand = m[cur]; //[a, b, c]
        for (int i = 0; i < cand.size(); ++i) {
            helper(res, path + cand[i], digits, level + 1, m); //
        }
    }
};