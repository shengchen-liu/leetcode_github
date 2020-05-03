class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for (char j : J) jewels.insert(j);
        
        int res = 0;
        for (char s : S) {
            if (jewels.count(s)) ++res;
        }
        return res;
    }
};