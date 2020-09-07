/*
events: {{x: L, height: H, type: entering},
        { x: R, height: H, type: leaving}}

events.sortbyX
ds = new ds()

for e in events:
    if entering(e):
        if e.height > ds.max() : ans += [e.height]
        ds.add(e.height)
    if leaving(e):
        ds.remove(e.height)
        if e.height > ds.max() : ans += ds.max()
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 左边节点的高度为负数，右边节点高度为正数
        vector<pair<int, int>> height; 
        for (auto &b : buildings) {
            height.push_back({b[0], -b[2]});
            height.push_back({b[1], b[2]});
        }
        
        // height: (2, -10), (9, 10), (3, -15), (7, 15), (5, -12), (12, 12), 
        // (15, -10), (20, 10), (19, -8), (24, 8)
        
        // sort by x
        sort(height.begin(), height.end());
        // height: (2, -10), (3, -15), (5, -12), (7, 15), (9, 10), (12, 12), 
        // (15, -10),  (19, -8),  (20, 10), (24, 8)
        
        multiset<int> m;
        m.insert(0);
        vector<vector<int>> res;
        int pre = 0; // 之前的高度
        int cur = 0; // 当前的高度
        
        for (auto &h : height) {
            if (h.second < 0) {
                // entering
                m.insert(-h.second);
            } else {
                // leaving
                m.erase(m.find(h.second));
            }
            cur = *m.rbegin(); // max height
            if (cur != pre) {
                res.push_back({h.first, cur});
                pre = cur;
            }
        }
        return res;  
    }
};