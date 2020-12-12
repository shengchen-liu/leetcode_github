/*
0  1  2  3  4  5
1, 1, 1, 2, 2, 3     
ij
i  j
i     j              erase

1, 1, 2, 2, 3    
      ij
      
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0, j = 0;
        while (i < nums.size()) {
            while (j < nums.size() && nums[i] == nums[j] && j - i <= 1){
                ++j;
            }
            if (j == nums.size())
                break;
            else if (nums[i] != nums[j]){
                i = j;
            } else {
                // erase
                nums.erase(nums.begin() + j);
            }
        }
        return (int)nums.size();
    }
};