class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainders(60);
        int cnt = 0;
        for (int t : time) {
            if (t % 60 == 0)  // check if a % 60 ==0 and b %% 60 == 0
                cnt += remainders[0];
            else {
                // check if a % 60  + b % 60 == 60
                cnt += remainders[60 - t % 60];
            }
            remainders[t % 60] ++; // update the hashmap
        }
        return cnt;
    }
};