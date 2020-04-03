class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int left = 1, right = 1e9 / (K + 1);
        while (left < right) {
             int mid = (left + right + 1) / 2; // total sweetness
            int cur = 0, cuts = 0;
            for (int s : sweetness) {
                if ((cur += s) >= mid) {
                    cur = 0;
                    if (++cuts > K) break;
                }
            }
            if (cuts > K)  left = mid;
            else right = mid - 1;
        }
        return left;
    }
};