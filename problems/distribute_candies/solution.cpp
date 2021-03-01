/*
candyType = [1,1,2,3]
n = 4
# of types: 3
n / 2 vs # of types
1. == : n / 2
2. <: n / 2
3. >: # of types
min(n/2, # of types)
*/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // # of types
        int cnt = 0;
        int n = candyType.size();
        unordered_set<int> s(candyType.begin(), candyType.end());
        cnt = s.size();
        return min(n / 2, cnt);
    }
};