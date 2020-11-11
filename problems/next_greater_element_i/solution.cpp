/*
nums1 = [4,1,2], nums2 = [1,3,4,2]
nums1
4, 1, 2
-1 3  -1
monotonic stack: incrementing order, only keep vals > curr
1, 3, 4, 2    next_greater  st
                            []
         i    -1            [2]
      i       -1            [4]   
   i          4             [3, 4]
i             3             [1, 3, 4]

hashmap num : num
2 : -1
4 : -1
3: 4
1: 3

iterate over nums1
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> m;
        int n = nums1.size();
        vector<int> res(n, 0);
        
        // monotonic stack based on nums2
        for (int i = nums2.size() - 1; i >=0; --i) {
            int cur = nums2[i];
            while (!st.empty() && cur > st.top()) {
                st.pop();
            }
            // hashmap
            if (!st.empty())
                m[cur] = st.top();
            else 
                m[cur] = -1;
            st.push(cur);
        }
        
        
        // iterate over nums1
        for (int i = 0; i < n; ++i) {
            res[i] = m[nums1[i]];
        }
        return res;
    }
};