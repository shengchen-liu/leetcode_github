/*
nums
choose 1 idx and remove it.
nums will changed
nums = [2,1,6,4]
remove idx0 => [1, 6, 4]
remove idx1 => [2, 6, 4]
remove idx2 => [2, 1, 4]
remove idx3 => [2, 1, 6]

fair:
    sum of odd-idx vals == sum of even-idx val
how many nums is fair?

initial guess:

* * * idx * * * * *
1. all valuse before idx
2. all values after idx
    even-idx => odd idx
    odd-idx => even idx

idea: prefix sum, suffix sum

prefix sum:
       2  1  6  4
pre 0  2  3  9  13
suf    13 11 10 4  0

pre_sum => even_pre, odd_pre
suffix_sum => even_suf, odd_suf

idx 1:
sum of even-idx vals = 
sum of odd-idx vals = ?
*/
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0; // how many fair nums
        
        // pre_eve, pre_odd, post_eve, post_odd
        vector<int> pre_even{0};
        vector<int> pre_odd{0};
        vector<int> post_even{0};
        vector<int> post_odd{0};
        
        // construct these four vects
        for (int i = 0; i < n; ++i) { // forward dir
            // i is odd or even
            if (i % 2 == 0) {
                pre_even.push_back(pre_even.back() + nums[i]);
            }
            // odd
            else {
                pre_odd.push_back(pre_odd.back() + nums[i]);
            }
        }
        
        
        for (int i = n - 1; i >= 0; --i) { // backward dir
            int j = n - 1 - i;
            if (j % 2 == 0) {
                post_even.push_back(post_even.back() + nums[i]);
            }
            // odd
            else {
                post_odd.push_back(post_odd.back() + nums[i]);
            }
            
        }
        
        // iterate over all idx
        for (int i = 0; i < n; ++i) {
            int even_sum = 0;
            int odd_sum = 0;
            // before i
            even_sum += pre_even[(i + 1) / 2];
            odd_sum += pre_odd[i / 2];
            
            // after i
            int j = n - 1 - i;
            // n is even or odd
            if (n % 2 == 0) {
                even_sum += post_even[(j + 1) / 2];
                odd_sum += post_odd[j / 2];
            } else {
                even_sum += post_odd[j / 2];
                odd_sum += post_even[(j + 1) / 2];
            }
            
            // compare even sum vs odd sum
            if (even_sum == odd_sum)
                ++cnt;
            
        }
        return cnt;
    }
};