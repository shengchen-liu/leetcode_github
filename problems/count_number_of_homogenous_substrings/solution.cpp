/*
homogenous : all chars are the same
substring: contiguous
1. find all largest homogeneous substring
2. cnt
s = "abbcccaa"
a: a * 1 => f(1)
bb : b * 2, bb * 1 => f(2)
ccc : c * 3, cc * 2, ccc * 1.  f(3)
aa : a * 2, aa * 1 => f(2)

1 + 2 + 1 + 3 + 2 + 1 + 2 + 1=13
*/
class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int res = 0;
        int n = s.size();
        if (n == 1)
            return 1;
        vector<int> cnts;
        int tmp = 1;
        // 001 =>2 
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                ++tmp;
            } else {
                cnts.push_back(tmp);
                tmp = 1;
            }
        }
        cnts.push_back(tmp);
        
        // 100001 * 10000
        for (int cnt : cnts) {
            // cout << cnt << endl;
            // 1 + 2 + ... + cnt
            // int sum = (1 + cnt) * cnt / 2;
            int sum = 0;
            for (int i = 1; i <= cnt; ++i) 
                sum = (sum + i) % mod;
            res += sum % mod;
        }
        return res;
    }
};