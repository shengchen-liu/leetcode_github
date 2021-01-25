/*
2, 0, 2, 1, 1, 0
ik             j
0, 0, 2, 1, 1, 2
ik          j
0, 0, 2, 1, 1, 2
   ik       j
0, 0, 2, 1, 1, 2
      ik    j
0, 0, 1, 1, 2, 2
      ik j
         k
   
all values before i == 0
all values after j == 2

nums[k] == 2:
    swap (nums[j], nums[k])
    --j
nums[k] == 0:
    swap (nums[i], nums[k])
    ++i，++k
nums[k] == 1:
    ++k

*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int k = 0;
        while (k <= j) {
            if (nums[k] == 0) {
                swap(nums[i++], nums[k++]);
            } else if (nums[k] == 2){
                swap(nums[j--], nums[k]);
            }
            else k++;
        }
    }
};