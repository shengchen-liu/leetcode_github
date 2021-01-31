/*
nums: n unique elements -> determine what this nums looks like
2d adjacentPairs: {u_i, vi}-> adjacent elements u_i, v_i inside nums

[2,1] : {2,1}, {1, 2}
[3,4] : {3,4}, {4, 3}
[3,2] : {3,2}, {2, 3}

{4,3,2,1} -> nums

2^{n-1}

hashmap -> val : vector<val> adjacent values
2: {1, 3}
1: {2} -> header
3: {4, 2}
4: {3} -> tail

[*]  *  *  *  [*]

1. dertmine the header:
    choose the vector size of 1 
2. find the rest of nums
    1 -> 2 -> 3 -> 4  
*/
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> m;
        // generate hashmap
        for (auto a : adjacentPairs) { //  {2, 1}
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }
        
        vector<int> res;
        // head
        for (auto a : m) { // key, vector<int>
            if (a.second.size() == 1) {
                res.push_back(a.first);
                res.push_back(a.second[0]);
                break;
            }
        }
        
        // rest of nums
        int n = adjacentPairs.size();
        while (res.size() <= n) {
            int tail = res.back();
            int prev = res[res.size() - 2];
            vector<int> next = m[tail];
            if (next[0] != prev) {
                res.push_back(next[0]);
            } else {
                res.push_back(next[1]);
            }
        }
        return res;
    }
    
};