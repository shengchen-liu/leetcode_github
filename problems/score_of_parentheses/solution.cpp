class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;
        stack<int> st;
        for (char c : S) {
            if  (c == '(') {
                st.push(res);
                res = 0;
            } else {
                res = st.top() + max(res *2, 1);
                st.pop();
            }
        }
        return res;
    }
};