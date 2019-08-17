/*
    3 
  2
1     1


          6 
        5
            4
      3
  2   
1   1       
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start + 1 < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[mid-1]){ // peak on right
                start = mid;
            }else{
                end = mid;
            }
        }
        
        if(nums[start] < nums[end]){
            return end;
        }else{
            return start;
        }
        
    }
};