// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

/*
[0,0,0,1,1]

start = 0, end=4, mid=2
isB(mid) = f
start = mid

*/

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start = 0, end = n - 1; // start = 0, end=4;
        while (start + 1 < end){
            int mid = start + (end - start)/2; // mid = 2; 2 + (4-2)/2 = 3
//             if true
            if (isBadVersion(mid + 1)){
                end = mid;
            }
            else{ // isBadVersion(mid) == false
                start = mid;  //start = 2
            }
        }
        if (isBadVersion(start + 1)){
            return start + 1;
        }
        else if (isBadVersion(end + 1)){
            return end + 1;
        }
        else{
            return -1;
        }
        
    }
};