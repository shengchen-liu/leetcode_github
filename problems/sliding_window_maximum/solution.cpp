class Solution {
public:
//     1. brute force
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//         if (nums.empty()) return result; 
//         for (int i = 0; i < nums.size() - k + 1; i++) {
//             // find max in the window
//             int max_num = INT_MIN;
//             for (int j = i; j < k + i; j++) {
//                 if (nums[j] > max_num) {
//                     max_num = nums[j];
//                 }
//             }
//             result.push_back(max_num);
//         }
//         return result;
//     }
    
//     2. BST
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            if (i >= k - 1) res.push_back(*st.rbegin());
        }
        return res;
        
    }
};