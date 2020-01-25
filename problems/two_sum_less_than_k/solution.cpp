class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        if (A.size() < 2) return -1;
        sort(A.begin(), A.end());  // O(nlogn)
        int result = -1;
        int i = 0;
        int j = A.size() - 1;
        while (i < j) { // O(N)
            int S = A[i] + A[j];
            if (S < K) {
                if (S > result) {
                    result = S;
                }
                i++;
            }
            else {
                j--;
            }
        }
        return result;
        // O(NlogN)
    }
};