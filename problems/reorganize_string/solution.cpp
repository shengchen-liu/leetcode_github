class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        unordered_map<char, int> m;
        for (auto c : S) ++m[c];
        priority_queue<pair<int, char>> pq;
        for (auto a : m) {
            if (a.second > (S.size() + 1) / 2) return "";
            pq.push({a.second, a.first});
        }
        
        while (pq.size() >= 2) {
            auto t1 = pq.top();
            pq.pop();
            auto t2 = pq.top();
            pq.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) pq.push(t1);
            if (--t2.first > 0) pq.push(t2);
        }
        
        if (pq.size() > 0) {
            res.push_back(pq.top().second); // only 1 left
        }
        return res;
    }
};