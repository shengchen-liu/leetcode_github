// O(n)
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int max_left;
//         int max_right;
//         int result = 0;
//         for (int i = 0; i < height.size(); ++i) {
//             max_left = 0;
//             max_right = 0;
//             // search left
//             for (int j = 0; j < i; ++j) {
//                 max_left = max(max_left, height[j] - height[i]);
//             }
//             // search right
//             for (int j = i; j < height.size(); ++j){
//                 max_right = max(max_right, height[j] - height[i]);
//             }
//             result += min(max_left, max_right);
//         }
//         return result;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int mn = min(height[left], height[right]); //0
            if (height[left] == mn) {
                ++left;
                while (height[left] < mn && left < right){ // can store water
                    result += mn - height[left++];
                }
            }
            else {
                --right;
                while (height[right] < mn && left < right) {
                    result += mn - height[right--];
                }
            }

        }
        return result;
        
    }
 };