class Solution {
public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result(n, -1);
//         // i :0,  j: 1, 2  i = 1, j: 2, 3
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n + i; ++j) {
//                 if (nums[j % n] > nums[i]) {
//                     result[i] = nums[j % n]; 
//                     break;
//                 }
//             }
//         }
//         return result;
        
//     }
    
/*
[1, 0, 3]
stack: 
i = 0, [1]   num: 0
1  [1, 0]   3  -> [-1, 3, -1]
2  [1] 3 -> [3, 3, -1]
[3]
3 [3], 1
4 [3], 0
5 [3]
*/
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num; st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};