class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char>> st; //[parent, child]
        unordered_set<char> ch; // all candidates
        string res;
        
        // insert all candidate chars into the hashset
        for (auto word : words) {
            ch.insert(word.begin(), word.end());
        }
        
        // compare each two neighboring words, store the pair into the treeset
        for (int i  = 0; (int) i < words.size() - 1; ++i) {
            int min_size = min(words[i].size(), words[i + 1].size());
            // compare each digit starting from digit 0;
            int j;
            for (j = 0; j < min_size; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    st.insert(make_pair(words[i][j], words[i + 1][j]));
                    // cout << i << endl;
                    // cout << words[i][j] << ',' << words[i + 1][j] << endl;
                    break;
                }
            }
        }
        
        // build in_degree vector
        vector<int> in_degree(256); // a char is stored in a 8-bit number
        for (auto edge : st) {
            ++in_degree[edge.second];
        }
        
        // build a queue
        queue<char> q;
        for (auto letter : ch) {
            if (in_degree[letter] ==0) {
                q.push(letter);
                res+=letter;
            }
        }
        
        // BFS
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            for (auto a : st) {
                if (a.first == c) {
                    --in_degree[a.second];
                    if (in_degree[a.second] == 0) {
                        q.push(a.second);
                        res+=a.second;
                    }
                }
            }
        }
        
        return res.size() == ch.size() ? res : "";
    }
};