/**
(A*0.5+7, A] 
**/
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        vector<int> numInAge(121), sumInAge(121);
        for (int age : ages) ++numInAge[age];
        for (int i = 1; i <= 120; ++i ){
            sumInAge[i] = numInAge[i] + sumInAge[i - 1];
        }
        for (int i = 15; i <= 120; ++i) {
            if (numInAge[i] == 0) continue;
            int cnt = sumInAge[i] - sumInAge[i * 0.5 + 7];
            res += cnt * numInAge[i] - numInAge[i];
        }
        return res;
    }
};