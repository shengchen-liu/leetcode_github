class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res(k);
        // count frequency
        unordered_map<string, int> hashmap;
        for (auto word : words) {
            ++hashmap[word];
        }
        
        // sorting policy. compare two pairs<word, frequency>
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first); 
        };
        
        // min_heap
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp) > q(cmp);

        for (auto f : hashmap) {
            q.push(f);
            if (q.size() > k) q.pop();
        }
        
        for (int i = q.size() - 1; i >= 0; --i) {
            res[i] = q.top().first;
            q.pop();
        }
        return res;
    }
};