/*
n=7
while ad > 1:
    r1: matchs = 7/2 = 3, ad= 3 + 7%2 = 4  update res
    r2: matchs = ad/2 = 4/2 = 2, ad = 2 + 4%2 = 2, update res
    r3: matches = ad /2 = 1, ad = 1, update res
*/
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        int matches = 0;
        int adv = n;
        while (adv > 1) {
            matches = adv / 2;
            adv = matches + adv % 2;
            res += matches;
        }
        return res;
    }
};