/*
min-product: min value * array's sum
for any non-empty subarray of nums, return the max "min-product"
min_val
arrays's sum
eg: 
1, 2, 3, 2   min_val    sum   min-product
ij           1          1     1*1=1
i  j         1          3     1*3=3
i     j      1          6     1*6=6
i        j   1          8     1*8=8
   ij        2          2     4
   i  j      2          5     10
   i     j   2          7     14
   
len = 1
max{1,2,3,2} = 3

len = n
min_val:1; sum:8 =>1*8=8

len = n - 1
{1,2,3} => 6
{2,3,2} => 2*7=14

len = n - 2
{1,2} => 1*3=3
{2,3} => 2*3=6
{3,2} => 2*5=15
*/
class Solution {
public:
int maxSumMinProduct(vector<int>& n) {
    long res = 0;
    n.push_back(0);
    vector<long> dp(n.size() + 1), st;
    for (int i = 0; i < n.size(); ++i)
       dp[i + 1] = dp[i] + n[i];
    for (int i = 0; i < n.size(); ++i) {
        while (!st.empty() && n[st.back()] > n[i]) {
            int j = st.back();
            st.pop_back();
            res = max(res, n[j] * (dp[i] - dp[st.empty() ? 0 : st.back() + 1]));
        }
        st.push_back(i);
    }
    return res % 1000000007;
}
};