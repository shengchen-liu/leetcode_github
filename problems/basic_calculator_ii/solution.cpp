class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int n = s.size();
        stack<int> st;
        char oper = '+';
        int num = 0;
        
        for (int i = 0; i < n; ++i) {
            // cout << num << endl;
            char c = s[i];
            // 1. digit
            if (c - '0' >= 0 && c - '9' <= 0) {
                num = num * 10 + (c - '0');
            } 
            if (c != ' ' && !(c - '0' >= 0 && c - '9' <= 0) || i == n - 1) {
                if (oper == '+'){
                    st.push(num);
                } else if (oper == '-') {
                    st.push(-num);
                } else if (oper == '*') {
                    int tmp = num * st.top();
                    st.pop();
                    st.push(tmp);
                } else if (oper == '/') {
                    int tmp = st.top() /  num;
                    st.pop();
                    st.push(tmp);
                }
                num = 0;
                oper = c;
            } 
        }
        
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};