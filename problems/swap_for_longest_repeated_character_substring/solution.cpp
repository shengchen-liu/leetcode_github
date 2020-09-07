class Solution {
public:
    int maxRepOpt1(string text) {
        int res = 1;
        // collect indexes of each char
        vector<vector<int>> idx(26);
        for (int i = 0; i < text.size(); ++i) {
            idx[text[i] - 'a'].push_back(i);
        }
        // a : 0, 2, 4
        // b : 1, 3
        
        // process each character, determine the longest substring
        for (int i = 0; i < 26; ++i) {
            int cnt = 1; // number of continous indices
            int cnt_pre = 0; // number of previous continous indices
            int mx = 0;
            for (int j = 1; j < idx[i].size(); ++j) {
                if (idx[i][j] == idx[i][j - 1] + 1) {
                    // continuous
                    ++cnt;
                } else {
                    cnt_pre = idx[i][j] == idx[i][j - 1] + 2 ? cnt : 0;                               cnt = 1;
                }
                mx = max(mx, cnt + cnt_pre);
            }
            res = max(res, mx + (idx[i].size() > mx ? 1 : 0));
        }
        return res;
    }
};