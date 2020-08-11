class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        queue<string> q;
        unordered_set<string> wordSet{wordList.begin(), wordList.end()};
        q.push(beginWord);
        
        // check neighbors
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string word = q.front();  // tmp: hit
                q.pop();
                if (word == endWord) return res + 1;
                for (int j = 0; j < word.size(); ++j) {
                    // candidates
                    string newWord = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        newWord[j] = c;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                    
                }
            }
            ++res;
        }
        return 0;
    }
};