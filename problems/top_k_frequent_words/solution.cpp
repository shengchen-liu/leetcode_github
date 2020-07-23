class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res(k);
        unordered_map<string, int> m;
        for (auto word : words) {
            ++m[word];
        }
        
        auto cmp = [](pair<string, int> &a, pair<string, int> &b){
            return a.second > b.second ||(a.second == b.second && a.first < b.first);
        };
        
        // min_heap
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        
        for (auto f : m) {
            pq.push(f);
            if (pq.size() > k) pq.pop();
        }
        
        for (int i = k - 1; i >= 0; --i) {
            res[i] = pq.top().first;
            pq.pop();   
        }
        
        return res;
    }
};