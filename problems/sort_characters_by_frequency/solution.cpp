/*
tree
t: 1
r: 1
e: 2

heap: [count, char]
2, e
1, t
1, r

*/
class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (auto a : m) pq.push({a.second, a.first});
        while (!pq.empty()) {
            auto t = pq.top(); //[2, e]
            pq.pop();
            res.append(t.first, t.second);
        }
        return res;
    }
};