class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0;
        int right = 0;
        for (right = 0; right < A.size(); ++right) {
            if (A[right] == 0) --K;
            if (K < 0) {
                if (A[left] == 0) ++K;
                ++left;
            }
        }
        return right - left;
    }
};