/*
abab => red blue red blue
a: red
b: blue

char : string
a : 
*/
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_set<string> st;
        return helper(pattern, 0, str, 0, m, st);
    }
    bool helper(string pattern, int p, string str, int r, unordered_map<char, string> &m, unordered_set<string> &st) {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        char c = pattern[p];
        for (int i = r; i < str.size(); ++i) {
            string t = str.substr(r, i - r + 1);
            if (m.count(c) && m[c] == t) {
                if (helper(pattern, p + 1, str, i + 1, m, st)) return true;
            } else if (!m.count(c)) {
                if (st.count(t)) continue;
                m[c] = t;
                st.insert(t);
                if (helper(pattern, p + 1, str, i + 1, m, st)) return true;
                m.erase(c);
                st.erase(t);
            }
        }
        return false;
    }
};