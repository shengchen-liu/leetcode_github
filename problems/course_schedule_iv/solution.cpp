/*
queries[i][0] -> querires[i][1]
[[0,1],[1,2],[2,3],[3,4]] n = 5   child, pa4rent
queries:  [[0,4],[4,0],[1,3],[3,0]]
hashmap parent : child
0:1
1:2
2:3
3:4

0->4: 0 is 4's parent? => T
    0->1->2->3->4
4->0: 4 is 0's parent? => F
1->3: 1 is 3's parent? =>T
    1->2->3
3->0: 3 is 0's parent? =>F
    
memorization:
check[i][j]: whether there is a path i -> j
initial: check[i][j] := 0
true: 1
false: -1

*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // hashmap.  parent : vector<child>
        unordered_map<int, vector<int>> m;
        for (auto a : prerequisites) {
            int parent = a[0];
            int child = a[1];
            m[parent].push_back(child);
        }
        
        // check matrix n x n
        vector<vector<int>> check(n, vector<int>(n, 0));
        
        
        // is there a path q[0] -> q[1]
        int k = queries.size();
        vector<bool> res(k, false);
        for (int i = 0; i < k; ++i) {
            auto query = queries[i];
            // q[0] -> q[1]?
            bool tmp = helper(query[0], query[1], m, check);
            res[i] = tmp;
        }
        
        return res;
    }
    
    // start -> end?
    bool helper(int start, int end, 
                unordered_map<int, vector<int>> &m, 
                vector<vector<int>> &check) {
        // termination
        if (check[start][end] != 0){
            if (check[start][end] == 1) return true;
            else return false;
        }

        // recursion
        // start's childs
        
        for (int child : m[start]){
            if (helper(child, end, m, check) || child == end){
                check[start][end] = 1;
                return true;
            }
        }
        
        check[start][end] = -1;
        return false;
    }
};