/*
nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
conditions:
(1) i < j
(2) nums1[i] <= nums2[j]

dist: j - i
if (1) (2) are both true:
    ++j
if (1) true, (2) false:
    ++i
if (1) false, (2) ?:
    ++j
nums1             nums2               i<=j     nums1[i] <= nums2[j]        dist
50,30,5,4,2       100,20,10,10,5        
i                 j                   t        t                           0
i                     j               t        f                           x
   i                  j               t        f                           x
   i                     j            t        f                           x
      i                  j            t        t                           0
      i                     j         t        t                           1
      i                        j      t        t                           2

*/
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        int res = 0;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            // if (1) true, (2) false
            if (i < j && nums1[i] > nums2[j])
                ++i;
            // else
            else 
                ++j;
            if (i == m || j == n)
                break;
            if (i <= j && nums1[i] <= nums2[j]){
                res = max(res, j - i);
                // cout << j - i << endl;
                // cout << "i:" << i << ", j: " << j << endl;
            }
        }
        return res;
    }
};