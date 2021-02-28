/*
nums1 = [1,2,3,4,5,6], m: 6 range: [6*1, 6*6], sum1 = 21
nums2 = [1,1,2,2,2,2], n: 6 range: [6*1, 6*6], sum2 = 10

10 ..... |  ..... 21

# of ops to make nums1 reach to x:
    if x == sum1:
        return 0
    if x > sum1:
        if (x - sum1 <= (6 - smallest in nums1))
            return 1
        else:
            set current smallest in nums1 = 6
            return 1 + f(sum1 + (6 - smallest in nums1))
*/
class Solution {
    
    int process(int* table1, int* table2, int diff) {
        int ans = 0;
        for (int k = 1; k <= 5 && diff > 0; k++) {
            int contrib = 6 - k;
            
            while (table2[k] > 0 && diff > 0) {
                diff -= contrib;
                ans++;
                table2[k]--;
            }
            while (table1[7 - k] > 0 && diff > 0) {
                diff -= contrib;
                ans++;
                table1[7 - k]--;
            }
        }
        
        return ans;
    }
    
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (6 * nums1.size() < nums2.size()) return -1;
        if (6 * nums2.size() < nums1.size()) return -1;
        int sum1 = 0;
        int table1[7] = {0};
        int sum2 = 0;
        int table2[7] = {0};
        
        for (int num : nums1) {
            sum1 += num;
            table1[num]++;
        }
        for (int num : nums2) {
            sum2 += num;
            table2[num]++;
        }
        
        if (sum1 == sum2) return 0;
        else if (sum1 > sum2) return process(table1, table2, sum1 - sum2);
        else return process(table2, table1, sum2 - sum1);
    }
};