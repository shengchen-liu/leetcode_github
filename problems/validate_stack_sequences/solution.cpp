/*
pushed: 1, 2,    3, 4, 5[i]
popped: 4, 5[j], 3, 2, 1

i: idx on pushed
j: idx on popped
st: vals pushed
i  j st.top() == popped[j]?
0  0 f, st.push(pushed[i]), ++i 
1  0 f, ++i, st.push(pushed[i])
2  0 f, ++i, st.push(pushed[i])
3  0 t, ++j, st.pop()
3  1 f, ++i, st.push(pushed[i])
4  1 t, ++j,  st.pop()
4  2 t, ++j,  st.pop()
4  3 t, ++j,  st.pop()
4  4 t, ++j.  st.pop() => st.empty() => true
check if j == n
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        int i = 0;
        int j = 0;
        for (i; i < n; ++i) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j;
            }
            
        }
        
        return j == n;
    }
};