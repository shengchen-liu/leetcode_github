/*
dfs(i):
    cnt >= 2
    [0, i) substr in hashset
    AND
    dfs(i, n, hashset) 
*/
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        
        // hashset
        unordered_set<string> wordSet(words.begin(), words.end());
        
        // dfs
        for (string word : words) {
            if (word.size() == 0)
                continue;
            dfs(wordSet, word, 0, 0, res);
        }
        return res;
    }
    
    // check whether substr[start, end) is a concatenated word
    bool dfs(unordered_set<string> &wordSet, string word, int start, int cnt, vector<string> &res) {
        // termination
        int n = word.size();
        if (start >= n && cnt >= 2){
            res.push_back(word);
            return true;
        }
            
        // recursion
        for (int i = 1; i <= n - start; ++i) {
            // substr
            string tmp = word.substr(start, i);
            if (wordSet.count(tmp) && dfs(wordSet, word, start + i, cnt + 1, res)) 
                return true;
        }
        return false;
        
    }
};