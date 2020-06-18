/*
if (A[mid])
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0;
        int end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] < A[mid + 1]) { // peak is on the right side
                start = mid;
            } else end = mid;
        }
        return A[start] > A[end] ? start : end;
    }
};