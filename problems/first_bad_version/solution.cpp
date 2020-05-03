/*
binary search
start, end

*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        int j = n;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (isBadVersion(mid)) j = mid;
            else i = mid + 1; // good version
        }
        if (isBadVersion(i)) return i;
        else return j;
    }
};