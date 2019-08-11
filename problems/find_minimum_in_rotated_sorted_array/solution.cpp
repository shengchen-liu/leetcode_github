/*
   7
  6
 5
4
          2
         1
        0 
        
  5
 4
3
    2
   1
   
start = 0
end = 6

while (start + 1 < end):
    if start < end:
        return start
    if start > end:

        mid = start + (end - start) /2 [3, 3 + 3/2=4]
        start vs. mid?
        if start < mid: 
            start = mid [3,]
        else start > mid:
            end = mid
    
    
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        
        while (start + 1 < end){
            if (nums[start] < nums[end]){
                return nums[start];
            }
            else{ // start > end
                int mid = start + (end - start) / 2; // mid = 2
                if (nums[start] < nums[mid]){
                    start = mid;
                }
                else{
                    end = mid;
                }
            }
        }
        if(nums[start] < nums[end]){
            return nums[start];
        }
        else{
            return nums[end];
        }

        
    }
};