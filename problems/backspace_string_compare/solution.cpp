class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = (int)S.size() - 1, j = (int)T.size() - 1, cnt1 = 0, cnt2 = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (S[i] == '#' || cnt1 > 0)) S[i--] == '#' ? ++cnt1 : --cnt1;
            while (j >= 0 && (T[j] == '#' || cnt2 > 0)) T[j--] == '#' ? ++cnt2 : --cnt2;
            if (i < 0 || j < 0) return i == j;
            if (S[i--] != T[j--]) return false;
        }
        return i == j;
    }
};