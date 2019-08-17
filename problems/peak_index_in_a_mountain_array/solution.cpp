/*
 2 
  1
0  0
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0, end = A.size() - 1; // start=0, end=3
        while(start + 1 < end){
            int mid = start + (end - start) / 2; // mid = 1
            if(A[mid] > A[mid - 1]){ // left side
                start = mid;
            }
            else{ // mid < A[mid-1] //right side
                end = mid;
            }
        }
        if(A[start] > A[end]){
            return start;
        }
        else{
            return end;
        }
        
    }
};