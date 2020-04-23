class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        return s.size() < nums.size() ? true : false;
    }
};