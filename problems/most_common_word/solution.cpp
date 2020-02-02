class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> strCnt;
        int mx = 0;
        for (auto &c : paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(paragraph);
        string t = "", res = "";
        while (iss >> t) {
            if (!ban.count(t) && ++strCnt[t] > mx) {
                mx = strCnt[t];
                res = t;
            }
        }
        return res;
    }
};