/**
nums1 : "91"
nums2 : "129"

add: 0
"1" + "9" + add => digit: 0, add: 1
"9" + "2" + add => digit: (9 + 2 + 1) % 10 = 2, add:(9 + 2 + 1) / 10 = 1
"1" + add => digit: (1 + 1) % 10 = 2, add = (1 + 1) / 10 = 0
res: "022"
reverse res: "220"
**/
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