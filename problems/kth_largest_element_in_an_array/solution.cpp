/*
min heap, size of k

*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](int &n1, int &n2) {return n1 > n2;};
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int num : nums) {
            if (pq.size() < k) pq.push(num);
            else if (num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();
        
    }
};