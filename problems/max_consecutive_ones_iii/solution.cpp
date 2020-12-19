
class Solution {
public:
  int longestOnes(vector<int>& A, int K) {
    int l = 0;
    int zeros = 0;
    int ans = 0;
    for (int r = 0; r < A.size(); ++r) {
      if (A[r] == 0) ++zeros;
      while (zeros > K)
        if (A[l++] == 0) --zeros;
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};