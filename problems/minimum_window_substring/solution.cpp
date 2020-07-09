class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> m;
        for (auto a : t) ++m[a];
        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        string res = "";
        for (int right = 0; right < n; ++right) {
            if (--m[s[right]] >= 0) ++count;
            while (count == t.size() ) {
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++m[s[left]] > 0) --count;
                ++left;
            }
        }
        return res;
    }
};