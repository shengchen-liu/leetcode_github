/*
nums1 = [1, 7, 11]
nums2 = [2, 4, 6]
[1, 2]
[1, 4] (5)
[1, 6](7), [7, 2](9)

max_heap : sort by sum of pairs
[1, 2], [1,]
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        auto cmp = [](vector<int> p1, vector<int> p2) {
            return p1[0] + p1[1] < p2[0] + p2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < min(k, (int) nums1.size()); ++i) {
            for (int j = 0; j < min(k, (int) nums2.size()); ++j) {
                if (q.size() < k) q.push({nums1[i], nums2[j]});
                else if (nums1[i] + nums2[j] < q.top()[0] + q.top()[1]) {
                    q.pop();
                    q.push({nums1[i], nums2[j]});
                }
            }
        }
        
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
        
    }
};