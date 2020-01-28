            /*
    对于一个长度为n的已排序数列a，若n为奇数，中位数为第(n/2+1)个数 , 
    若n为偶数，则中位数=[第(n/2)个数 + 第(n/2+1)个数] / 2
    如果我们可以在两个数列中求出第K小的元素，便可以解决该问题
    不妨设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素
    取A[k / 2] B[k / 2] 比较，
    如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法)
    反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的
    k - k / 2小元素，于是得到了数据规模变小的同类问题，递归解决
    如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好。
    */
        

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double result;
        
        if (sum == 1) {
            result = findKthLargest(nums1, 0, nums2, 0, 1);
        } else {
            result = (findKthLargest(nums1, 0, nums2, 0, (sum + 1) / 2) + findKthLargest(nums1, 0, nums2, 0, (sum + 2) / 2)) / 2.0;    
        }
        return result;
    }
     
    double findKthLargest(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        // corner case
        if (i >= nums1.size()){
            return nums2[j + k - 1];
        }
        if (j >= nums2.size()){
            return nums1[i + k - 1];
        }
        // k == 1
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }
        int A_key = i + k / 2 - 1 >= nums1.size() ? INT_MAX : nums1[i + k / 2 - 1];
        int B_key = j + k / 2 - 1 >= nums2.size() ? INT_MAX : nums2[j + k / 2 - 1];
        if (A_key < B_key) {
            return findKthLargest(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKthLargest(nums1, i, nums2, j + k / 2, k - k / 2);
        }
        

    }
};