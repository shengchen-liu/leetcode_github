// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int left = 0; 
//         int right = nums.size() - 1;
//         int cur = 0;
//         while (cur <= right) {
//             if (nums[cur] == 0) {
//                 swap(nums[cur], nums[left]);
//                 left++;
//             }
//             if (nums[cur] == 2) {
//                 swap(nums[cur], nums[right]);
//                 right--;
//             }
//             else{
//                 ++cur;
//             }
//         }
        
//     }
// };

// counting sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3);
        for (int num : nums) ++colors[num];
        for (int i = 0, cur = 0; i < 3; ++i) {
            for (int j = 0; j < colors[i]; ++j) {
                nums[cur++] = i;
            }
        }
    }
};