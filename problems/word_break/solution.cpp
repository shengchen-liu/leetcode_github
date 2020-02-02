class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set wordSet(wordDict.begin(), wordDict.end());
        queue<int> queue;
        queue.push(0);
        vector<bool> visited(s.size(), false);
        while (!queue.empty()) {
            int start = queue.front();
            queue.pop();
            if (!visited[start]) {
                for (int i = start + 1; i < s.size() + 1; ++i) { // i: 1
                    if (wordSet.count(s.substr(start, i - start))) {
                        queue.push(i);
                        if (i == s.size()) {
                            return true;
                        }
                    }
                }
                visited[start] = true;                
            }
        }
        return false;
        
    }
    
};