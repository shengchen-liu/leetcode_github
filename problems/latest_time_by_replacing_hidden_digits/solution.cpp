/*
2?:?0            digit
    i            9 or given
   i             5 or given
 i               if tims[0] == 2 => 3.  if times[0] == 0, 1 => 9  if times[0] = ? => 3, times[0] = 2
i                
traverse each digit:
pos1: best 2

*/
class Solution {
public:
    string maximumTime(string time) {
        string res = time;
        if (res[4] == '?') {
            res[4] = '9';
        }
        if (res[3] == '?')
            res[3] = '5';
        if (res[1] == '?') {
            // 3 cases
            if (res[0] == '2') {
                res[1] = '3';
            } else if (res[0] == '1' || res[0] == '0') {
                res[1] = '9';
            } else{
                res[1] = '3';
                res[0] = '2';
            }
        }
        if (res[0] == '?') {
            if ((res[1] - '0') < 4) {
                res[0] = '2';
            } else {
                res[0] = '1';
            }
        }
        return res;
    }
};