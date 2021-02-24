class Solution {
public:
    bool isSubsequence(string x, string y) {
        int j = 0;
        for (int i = 0; i < y.size(); ++i) {
            if (x[j] == y[i])
                ++j;
        }
        return j == x.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for (string str : d) {
            if (isSubsequence(str, s)) {
                if (str.size() > res.size() || (str.size() == res.size() && str < res)) {
                    res = str;
                }
            }
        }
        return res;
    }
};