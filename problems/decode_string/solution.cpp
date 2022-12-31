/*
stack
1) [ : begin sth
2) ] : end of sth.  start to pop stack until reach to [  => [....] 
3) digit: updat the cnt
*/
class Solution {
public:
    string decodeString(string s) {
        string t = "";
        stack<int> s_cnt;
        stack<string> s_str;
        int cnt = 0;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                cnt = cnt * 10 + (c - '0') ;
            } else if (c == '[') {
                s_cnt.push(cnt);
                s_str.push(t);
                cnt = 0;
                t = "";
            } else if (c == ']') {
                int k = s_cnt.top();
                s_cnt.pop();
                for (int i = 0; i < k; ++i) {
                    s_str.top() += t;
                }
                t = s_str.top();
                s_str.pop();
            } else {
                t += c;
            }
        }
        return s_str.empty()? t : s_str.top();
    }
};