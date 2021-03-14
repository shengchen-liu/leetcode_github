/*
bank
kanb
1001

b,k
cnt = 2
1. s1.size != s2.size => false
2. s1.char_freq != s2.char_freq => false

*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m != n)
            return false;
        int res = true;
        int cnt = 0;
        char a1, b1;
        
        for (int i = 0; i < m; ++i) {
            char c1 = s1[i];
            char c2 = s2[i];
            if (c1 != c2) {
                if (cnt == 0) {
                    cnt = 1;
                    a1 = c1;
                    b1 = c2;
                    res =  false;
                } else if (cnt == 1) {
                    cnt++;
                    if (c1 == b1 && c2 == a1)
                        res = true;
                    else 
                        return false;
                } else 
                    return false;
            }
        }
        return res;

    }
};