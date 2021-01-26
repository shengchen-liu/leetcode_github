/*
candies
for each kid:
    distribute extraCandies, such that this kid has the greatest number of candies

extra: 3
curLaregest = 5

2, 3, 5, 1, 3
-3 -2 0  -4 -2

compare diff[i] + extra >= 0
*/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n, false);
        // laregest
        int largest = 0;
        for (int x : candies) {
            largest = max(largest, x);
        }
        for (int i = 0; i < n; ++i) {
            int x = candies[i];
            if (x + extraCandies >= largest)
                res[i] = true;
        }
        return res;
    }
};