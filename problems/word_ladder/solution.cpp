class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet{wordList.begin(), wordList.end()};
        queue<string> q;
        q.push(beginWord);
        //BFS
        int layer = 0;
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord) return layer + 1;
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
            ++layer;
        }
        return 0;
        
    }
};