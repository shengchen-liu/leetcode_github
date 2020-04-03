/**
binary search:
the left bound is max(weights)
the right bound is sum(weights)
**/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0;
        int right = 0;
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2; // mid is the capacity
            int need = 1; // how many days needed
            int cur = 0; // accumlated weights in current day
            for (int w : weights) {
                if (cur + w > mid) {
                    need += 1; // split one more day
                    cur = 0;
                }
                cur += w; // acculate on the same day
            }
            
            // now we have got how many days we need
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};