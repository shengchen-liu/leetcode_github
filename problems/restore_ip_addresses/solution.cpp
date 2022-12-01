class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path = "";
        int cnt = 0;
        dfs(0, cnt, s, path, res);
        return res;
    }

    void dfs(int start, int cnt, const string s, string path, vector<string>& res) {
        // termination
        if(start == s.size() && cnt == 4) {
            res.push_back(path);
            return;
        } else if (start == s.size() || cnt == 4) {
            return;
        }

        // recrusion
        for (int i = start; i < s.size(); ++i) {
            string curStr = s.substr(start, i - start + 1); // "2"
            // check curStr
            if (!isValid(curStr)) break;
            dfs(i + 1, cnt + 1, s, path + curStr + (cnt < 3? "." : ""), res);
        }
    }

    bool isValid(string input) {
        if (atoi(input.c_str()) > 255 || (input.size() > 1 && input[0] == '0'))
            return false;
        return true;
    }
};