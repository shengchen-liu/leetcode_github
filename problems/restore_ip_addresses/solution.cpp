/*
25525511135
0~255
255, 255, 111, 35

*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
               vector<string> res;
        helper(s, 0, "", res);
        return res; 
    }
    void helper(string s, int n, string out, vector<string> &res) {
        if (n == 4) {
            if(s.empty()) res.push_back(out);
        } else {
            for (int k = 1; k < 4; ++k) {
                if (s.size() < k) break;
                //check the current substr
                int val = atoi(s.substr(0, k).c_str());
                if (val >= 256 || k != to_string(val).size()) continue;
                helper(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), res);
            }
        }
    }
};