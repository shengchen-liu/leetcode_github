class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int l = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int r = 0; r < s.size(); ++r) {
            if (--letterCnt[s[r]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > r - l + 1) {
                    minLen = r - l + 1;
                    res = s.substr(l, minLen);
                }
                if (++letterCnt[s[l]] > 0) --cnt;
                ++l;
            }
        }
        return res;
    }
};