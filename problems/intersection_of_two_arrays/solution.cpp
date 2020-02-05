class Solution {
public:
    // [4, 5, 9]
    // [4, 4, 8, 9, 9]
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set set1(nums1.begin(), nums1.end());
        unordered_set set2(nums2.begin(), nums2.end());
        vector<int> result;
        for (int i : set2) {
            if (set1.count(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};