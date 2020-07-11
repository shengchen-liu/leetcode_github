/*
1. Merge two accounts if they have same emails
2. Different people if they :
    (1) have different name
    (2) Names are the same, BUT emails are different
*/
class Solution {
public:
    int find(int x) {
        if (x == father[x]) return x;
        return father[x] = find(father[x]);
    }
    
    void connect (int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) father[root_b] = root_a;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for (int i = 0; i < n; ++i) father.push_back(i);
        
        unordered_map<string, int> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (m.count(accounts[i][j])) {
                    int k = m[accounts[i][j]];
                    if (accounts[k][0] == accounts[i][0]) connect(i, k);
                } else {
                    m[accounts[i][j]] = i;
                }
            }
        }
        
         // 以union过的accounts ids来构造合并后的accounts，并保持string order
        map<int, set<string>> merged;
        for (int i = 0; i < n; ++i) {
            int k = find(i);
            merged[k].insert(accounts[i].begin(), accounts[i].end());
        }

        // final result
        vector<vector<string>> res;
        for (auto i : merged) {
            res.push_back(vector<string>(i.second.begin(), i.second.end()));
        }
        
        return res;
    }
    
private:
    vector<int> father;
};