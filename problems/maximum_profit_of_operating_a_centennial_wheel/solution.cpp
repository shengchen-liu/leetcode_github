class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int res = 0;
        int idx = -1;
        int waiting = customers[0];
        vector<int> profit;
        
        int i = 1;
        int tmp = 0;

        while (waiting > 0 || i < customers.size()) {
            if (waiting < 4) {
                tmp = tmp + waiting * boardingCost - runningCost;
                profit.push_back(tmp);
                waiting = 0;
            } else {
                waiting -= 4;
                tmp = tmp + 4 * boardingCost - runningCost;
                profit.push_back(tmp);
            }
            // cout << tmp << endl;
            if (i < customers.size()) {
                waiting += customers[i];
                ++i;
            }
        }
        
        for (int i = 0; i < profit.size(); ++i) {
            if (profit[i] > res) {
                res = profit[i];
                idx = i + 1;
            }
        }
        return idx;
        
//         // split into valid groups
//         vector<int> group;
//         for (int c : customers){
//             if (c <= 4) {
//                 group.push_back(c);
//             } else {
//                 while (c / 5 > 0) {
//                     group.push_back(4);
//                     c = c - 4;
//                 }
//                 group.push_back(c);
//             }
//         }
        
//         int n = group.size();
//         vector<int> profit(n, 0);
        
//         for (int i = 0; i < n; ++i) {
//             if (i == 0) {
//                 profit[i] = group[i] * boardingCost - runningCost;
//             } else {
//                 profit[i] = profit[i - 1] + group[i] * boardingCost - runningCost;
//             }
//             if (profit[i] > res) {
//                 res = profit[i];
//                 idx = i + 1;
//             }
//         }
        
//         return idx;
    }
};