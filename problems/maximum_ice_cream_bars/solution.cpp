class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // sort
        sort(costs.begin(), costs.end());
        
        int res = 0;
        for (int cost : costs) {
            if (coins < cost)
                break;
            coins -= cost;
            ++res;
        }
        
        return res;
    }
};