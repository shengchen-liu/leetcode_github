class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> hashset;
        for (int i = 0; i < n; ++i) {
            if (hashset.count(nums[i])) return true;
            hashset.insert(nums[i]);
            if (hashset.size() > k) {
                hashset.erase(nums[i - k]);
            }
        }
        return false;
    }
};