class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        
        stack<char> par;
        for (char c : s) {
            if ( c == '(' || c == '{' || c == '[') {
                par.push(c);
            }
            else { // right
                if (par.empty()) return false;
                char last_c = par.top();
                // check if they can pair
                if (last_c == '(' && c != ')')  return false;
                if (last_c == '{' && c != '}')  return false;
                if (last_c == '[' && c != ']')  return false;
                par.pop();
            }
        }
        return par.empty();
    }
};