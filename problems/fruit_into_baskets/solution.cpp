/*
a sliding window that covers consecutive trees.  The number of unique fruits must be <= 2.
We want to find the max size of this window.
*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        int res = 0;
        unordered_map<int, int> unique; // type: count
        int start = 0;
        for (int i = 0; i < n; ++i) {
            ++unique[tree[i]];
            while (unique.size() > 2) {
                if (--unique[tree[start]] == 0) {
                    unique.erase(tree[start]);
                }
                ++start;
            }
            res = max(res, i - start + 1);                
        }
        return res;
    }
};