class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // build a graph
        unordered_map<string,  multiset<string>> m;
        for (auto ticket : tickets) {
            m[ticket[0]].insert(ticket[1]);
        }
        vector<string> res;
        dfs(m, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }
    
    void dfs(unordered_map<string,  multiset<string>>& m, string s, vector<string>& res) {
        while(m[s].size()) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(m, t, res);
        }
        res.push_back(s);
    }
};