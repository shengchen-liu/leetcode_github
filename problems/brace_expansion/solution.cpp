class Solution {
public:
vector<string> expand(string S) {
        vector<string> ans;
        int n = S.size();
        function<void(int, string&)> dfs = [&](int idx, string& cur)->void{
            if (idx>=n){
                ans.push_back(cur);
                return;
            }
            // for the lexicographical ordering
            priority_queue<char, vector<char>, greater<char>> opts;
            if (S[idx] == '{'){
                int start = idx+1;
                while (S[idx]!='}'){
                    // ex: a,b,c,
                    if (S[idx] == ','){
                        opts.push(S[idx-1]);
                        start = idx+1;
                    }
                    idx++;
                }
                // ex: S[idx] = 'd}' 
                opts.push(S[idx-1]);
            } else {
                opts.push(S[idx]);
            }
            
            while (!opts.empty()){
                auto opt = opts.top(); opts.pop();
                cur.push_back(opt);
                dfs(idx+1, cur); // check next idx (a.k.a idx + 1)
                cur.pop_back();
            }
            
        };
        string cur;
        dfs(0, cur);
        
        return ans;
    }
};