class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> dict (26);
        for (int i = 0; i < source.size(); ++i) {
            dict[source[i] - 'a'] = true;
        }
        int j = 0;
        int res = 1;
        for (int i = 0; i < target.size(); ++i, ++j) {
            if (!dict[target[i] - 'a']) return -1;
            while (j < source.size() && source[j] != target[i]) ++j;
            if (j == source.size()) {
                j = -1;
                ++res;
                --i;
            } 
        }
        return res;
    }
};