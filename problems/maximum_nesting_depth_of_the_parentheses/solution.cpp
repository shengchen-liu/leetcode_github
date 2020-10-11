class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int cnt = 0;
        for (char c : s) {
            if (c == '(') {
                ++cnt;
                res = max(res, cnt);
            } else if (c == ')') {
                --cnt;
            }
        }
        return res;
        
    }
};