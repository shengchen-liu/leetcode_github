class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for (char c : S) ++m[c]; // [char, count]
        for (auto a : m) {
            if (a.second > (S.size() + 1) / 2) return "";
            pq.push({a.second, a.first}); //[count, char]
        }
        
        while (pq.size() >= 2) {
            auto t1 = pq.top(); pq.pop(); // top
            auto t2 = pq.top(); pq.pop(); // second top
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