/*
1-23-45 6
1. remove all spaces and dashes
    123456 n:6 => 3, 3
2. group from left to right into groups of 3, until there are <= 4 digits
    2 digits: A single block of length 2.
    3 digits: A single block of length 3.
    4 digits: Two blocks of length 2 each.

123 4-567 => 1234567 n: 7 => 3, 2, 2
123, 45, 67

12345678 n: 8 => 3,3,2

2: 2
3: 3
4: 2,2

5: 3,2
6: 3,3
7: 3,2,2

8: 3,3,2  8 % 3 = 2
9: 3,3,3  9 % 3 = 0
10: 3,3,2,2 10 %3=1

n: 3,3,3,...,3,
n % 3 => 3 cases
*/


class Solution {
public:
    string reformatNumber(string number) {
        // 1. remove all spaces
        string tmp;
        for (char c : number){
            if (c >= '0' && c <= '9')
                tmp += c;
        }
        
        // split to cases
        int n = tmp.size();
        int rem = n % 3;
        // front 3's commons (n - 2) / 3
        string res;
        int common = (n - 2) / 3;
        int idx = 0;
        for (int i = 0; i < common; ++i){
            for (int j = 0; j < 3; ++j) {
                res += tmp[idx];
                ++idx;
            }
            res += '-';
        }
        
        // 3 cases
        if (rem == 2) {
            res += tmp[n - 2];
            res += tmp[n - 1];
        } else if (rem == 0) {
            res += tmp[n - 3];
            res += tmp[n - 2];
            res += tmp[n - 1];
        } else {
            // rem == 1
            res += tmp[n - 4];
            res += tmp[n - 3];
            res += '-';
            res += tmp[n - 2];
            res += tmp[n - 1];
        }
        return res;
        
    }
};