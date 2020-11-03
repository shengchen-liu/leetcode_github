class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        vector<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.back()] < nums[i]) {
                res[st.back()] = nums[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.back()] < nums[i]) {
                res[st.back()] = nums[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        return res;
    }
};