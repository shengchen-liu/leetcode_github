/*
3+2*2
case1: digit
update num

case2: +
sign: 1
stack.push num

case3: -
sign: -1
stack.push num

2 * 2 + 1
case4: * => handle the operator now
stack push num
operator: *

case5: /
stack push num
operator: /

case 6: space
if operator is * or /:
    pop stack.top
    num = num [operator] pop.top
    push back num to stack

case 7: end of the string
    




*/
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int curNumber = 0;
        int last = 0;
        char op = '+';
        int n = s.size();
        
        // iter
        for (int i = 0; i < n; ++i) {
            char cur = s[i];
            // case 1: digit
            if (cur >= '0' && cur <= '9'){
                curNumber = curNumber * 10 + (cur - '0');
            } 
            if ((cur < '0' && cur != ' ') || i == n - 1) {
                if (op == '+'){
                    res += last;
                    last = curNumber;
                }
                else if (op == '-'){
                    res += last;
                    last = -curNumber;
                }
                else if (op == '*' ){
                    last = last * curNumber;
                } else if (op = '/'){
                    last = last / curNumber;
                }
                op = cur;
                curNumber = 0;
            }
        }
            
        res += last;
        return res;
    }
};