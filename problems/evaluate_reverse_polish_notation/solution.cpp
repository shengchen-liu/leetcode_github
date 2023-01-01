class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int tmp = 0;
        for (string c : tokens) {
            if (c == "+" || c =="-" || c == "*" || c == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (c == "+") 
                    tmp = a + b;
                else if (c == "-")
                    tmp = b - a;
                else if (c == "*")
                    tmp = a * b;
                else 
                    tmp = b / a;
                st.push(tmp);
            } else 
                st.push(stoi(c));
        }
        return st.top();
    }
};