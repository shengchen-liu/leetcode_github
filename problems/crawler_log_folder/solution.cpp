/*
../  -1
./ 0
x/ +1
*/
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (auto log : logs) {
            // string
            //1. ../
            if (log[0] == '.' && log[1] == '.') {
                if (cnt > 0) --cnt;
            }
            // 2.  x/
            else if (log[0] != '.') ++cnt;
        }   
        return cnt;
    }
};