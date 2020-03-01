class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = INT_MAX;
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }
            res = max(res, price - minPrice);
        }
        return res;
        
    }
};