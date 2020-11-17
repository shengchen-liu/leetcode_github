/*
deadends = ["0201","0101","0102","1212","2002"]
target = 0202
initial: 0000

each digit has 2 options: +1, -1
back-tracking

bool dfs(cand, cnt, min_cnt):
    # termination
    visited, blocked, target

    #recursion
    for every pos i in cand:
        cand[i]++
        a = dfs(cand, cnt + 1, visited)
        cand[i]--

        cand[i]--
        b = dfs(cand, cnt + 1, visited)
        cand[i]++
        res = res || a || b
    return res
    
    
    
*/


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        string init = "0000";
        if (dds.count(init)) return -1;
        
        visited.insert(init);
        q.push(init);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                // get current string
                string t = q.front();
                q.pop();
                if (t == target) return res;
                
                // check its neighbor
                vector<string> neighbors = nbrStrs(t); // 8 neighbors
                for (auto s : neighbors) {
                    if (visited.count(s) || dds.count(s))
                        continue;
                    q.push(s);
                    visited.insert(s);
                }
            }
            ++res;
        }
        return -1;
    }
    
    vector<string> nbrStrs(string key) {
        vector<string> res;
        for (int i = 0 ; i < 4; i++) {
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
         }
        return res;
    }
};