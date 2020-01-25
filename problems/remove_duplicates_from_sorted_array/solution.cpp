class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int p1 = 0;
        int p2 = 0;
        while ( p2 < nums.size()) {
            if (nums[p2] > nums[p1]) {
                nums[++p1] = nums[p2++];
            }
            else {
                p2++;
            }
        }
        return p1 + 1;
        
    }
};