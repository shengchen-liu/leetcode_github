class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashset;
        for (auto word : wordDict) hashset.insert(word); 
        //[cats, dog, sand, and, cat]
        vector<bool> visited(s.size(), false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (!visited[start]) {
                for (int i = start + 1; i < s.size() + 1; ++i) {
                    if (hashset.count(s.substr(start, i - start))) {
                        q.push(i);
                        if (i == s.size()) return true;
                    }
                }
                visited[start] = true;
            }
        }
        return false;
    }
};