class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0) return s;
        string res = "", t = "";
        istringstream is(s);
        while (is >> t) {
            reverse(t.begin(), t.end());
            res += t + " ";
        }
        res.pop_back();
        return res;
    }
};