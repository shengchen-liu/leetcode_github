/*
123
78

digit 0: 3 + 8 = 11 -> 1, add: 1
digit 1: 2 + 7 + add = 2 + 7 + 1 = 10 -> 0, add: 1
digit 2: 1 + 0 + add = 1 + 1 = 2, add: 0
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int i = n1 - 1;
        int j = n2 - 1;
        string res = "";
        int add = 0;
        
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int tmp = a + b + add;
            res.insert(res.begin(), tmp % 10 + '0');
            add = tmp / 10;
        }
        
        return add ? "1" + res : res;
    }
};