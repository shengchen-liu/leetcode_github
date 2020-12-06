/*
"G", "()" and/or "(al)"
G()(al) -> 
G
o
al

"G()()()()(al)"
G
o
o
o
o
al
iterate:
1. s[i] == G => G
2. s[i] == ( and s[i+1]== ) => o
3. s[i] == ( and s[i+1]!= ) => al
else: continue

*/
class Solution {
public:
    string interpret(string command) {
        string res = "";
        int n = command.size();
        if (n == 1) return "G";
        
        for (int i = 0; i < n - 1; ++i) {
            if (command[i] == 'G')
                res += "G";
            else if (command[i] == '(' && command[i + 1] == ')')
                res += "o";
            else if (command[i] == '(' )
                res += "al";
        }
        if (command[n - 1] == 'G')
            res += "G";
        return res;
        
    }
};