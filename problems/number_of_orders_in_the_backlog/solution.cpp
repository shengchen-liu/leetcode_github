class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int res = 0;
        int mod = 1e9 + 7; 
        priority_queue<pair<int, int>> buyOrders; // max heap
        
        auto cmp = [](const pair<int, int> order1, const pair<int, int> order2){
          return order1.first > order2.first;  
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> sellOrders(cmp); // min heap
        
        for (auto order : orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];
            // buy
            if (type == 0) {
                while (!sellOrders.empty() && amount > 0) {
                    auto tmp = sellOrders.top();
                    int sellPrice = tmp.first;
                    int tmpAmount = tmp.second;
                    // cout << sellPrice << endl;

                    if (price < sellPrice){
                      break;
                    }
  
                    else {
                        sellOrders.pop();
                        int minAmount = min(amount, tmpAmount);
                        amount -= minAmount;
                        tmpAmount -= minAmount;
                        // cout << amount << endl;
                    }
                    if (tmpAmount > 0) {
                        sellOrders.push({sellPrice, tmpAmount});
                    }
                     // cout << "size" << sellOrders.size() << endl;
                    // cout << "amount" << amount << endl;
                }
                if (amount > 0) {
                    buyOrders.push({price, amount});
                    // cout << amount << ", " << type << endl;
                }
                // cout << amount << endl;
            } else {
            // sell
                while (!buyOrders.empty() && amount > 0) {
                    auto tmp = buyOrders.top();
                    int buyPrice = tmp.first;
                    int tmpAmount = tmp.second;
                    if (price > buyPrice)
                        break;
                    else {
                        buyOrders.pop();
                        int minAmount = min(amount, tmpAmount);
                        amount -= minAmount;
                        tmpAmount -= minAmount;
                    }
                    if (tmpAmount > 0) {
                        buyOrders.push({buyPrice, tmpAmount});
                    }
                }
                if (amount > 0) {
                    sellOrders.push({price, amount});
                    // cout << amount << ", " << type << endl;

                }
            }
        }
                
        while (!sellOrders.empty()) {
            auto order = sellOrders.top();
            sellOrders.pop();
            res = (res + order.second) % mod;
        }
        
        while (!buyOrders.empty()) {
            auto order = buyOrders.top();
            buyOrders.pop();
            res = (res + order.second) % mod;
        }
        
        return res;
    }
};