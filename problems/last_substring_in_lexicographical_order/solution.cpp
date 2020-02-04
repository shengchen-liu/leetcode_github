class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        vector<int> pre(n, 0);
        int start = 0;
        int to_match = 0;
        int visited = -1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] > s[start]) {
                start = i;
                to_match = start;
            } 
            else if (s[to_match] == s[i]) {
                if (i - start <= 2 * (to_match - start)) {
                    pre[to_match] = to_match - start;
                    start = to_match;
                    to_match = start + 1;
                }
                else {
                    to_match ++;
                }
            }
            else if (s[to_match] > s[i]) {
                to_match = start;
            }
            else if (s[to_match] < s[i]) {
                start = i - (to_match - start);
                to_match = start;
            }
        }
        int tot = 0;
        int pos = start;
        while (pos > 0) {
            tot += pre[pos];
            pos -= pre[pos];
            if (pre[pos] == 0) break;
        }
        return s.substr(start - tot);
    }
};