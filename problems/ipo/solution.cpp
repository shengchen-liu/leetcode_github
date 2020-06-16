class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>> maxH;  // [profit, capital], sort by profit
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH; // sort by capital, the smallest capital is on the top of min heap
        for (int i = 0; i < Capital.size(); ++i) {
            minH.push({Capital[i], Profits[i]});
        }
        
        for (int i = 0; i < k; ++i) {
            while (!minH.empty() && minH.top().first <= W) {
                auto t = minH.top();
                minH.pop();
                maxH.push({t.second, t.first});
            }
            if (maxH.empty()) break;
            W += maxH.top().first;
            maxH.pop();
        }
        return W;
    }
};