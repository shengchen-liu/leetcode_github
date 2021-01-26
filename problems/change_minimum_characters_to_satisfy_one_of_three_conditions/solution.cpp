class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.size();
        int n = b.size();
        int res = m + n;
        vector<int> c1(26), c2(26);
        for (char c : a) {
            c1[c - 'a']++;
        }
        for (char c : b) {
            c2[c - 'a']++;
        }
        
        for (int i = 0; i < 26; ++i) {
            // case 3
            res = min(res, m + n - c1[i] - c2[i]); 
            if (i > 0) {
                c1[i] += c1[i - 1];
                c2[i] += c2[i - 1];
            }
            if (i < 25) {
                // case 1.  all chars in a < i and all chars in b >= i
                res = min(res, m - c1[i] + c2[i]);
                // case 2
                res = min(res, n - c2[i] + c1[i]);
            }
        }
        return res;
    }
};