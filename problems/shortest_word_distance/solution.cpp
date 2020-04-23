class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i1 = -1, i2 = -1;
        int res = words.size();
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) i1 = i;
            else if (words[i] == word2) i2 = i;
            
            if (i1 != -1 && i2 != -1) {
                res = min(res, abs(i2 - i1));
            }
        }
        return res;
    }
};