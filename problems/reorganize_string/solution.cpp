/**
aab => aba
aaabc:
'a': 3, 2, 1, 0
'b': 1, 0
c: 1, 0
a, b, a, c, a

heap: store chars by ordereing its appearances in descending order => [3: a, 1: b, 1: c]
while heap is not empty:
    cur : heap's top
    next: second top if exist, else return false
    heeap.pop()
    heap.pop()
    heap.push(t1--)
    heap.push(t2--)
return true

**/
class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (char c : S) ++m[c];
        for (auto a : m) {
            if (a.second > (S.size() + 1) / 2) return "";
            q.push({a.second, a.first}); //[#, char]
        }
        
        while (q.size() >= 2) {
            auto t1 = q.top(); q.pop(); // top
            auto t2 = q.top(); q.pop(); // 2nd top
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) q.push(t1);
            if (--t2.first > 0) q.push(t2);
        }
        
        if (q.size() > 0) res.push_back(q.top().second); // only 1 left
        return res;
    }
};