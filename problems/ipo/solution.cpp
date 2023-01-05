class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        int ptr = 0;
        for (int i = 0; i < k; ++i) {
            // find all cap <= w
            while (ptr < n && projects[ptr].first <= w) {
                pq.push(projects[ptr].second);
                ++ptr;
            }
            // get the largest profit
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};