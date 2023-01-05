class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> low;
        multiset<int> high;
        vector<double> medians;

        for (int i = 0; i < n; ++i) {
            // remove outgoing
            if (i >= k) {
                if (nums[i - k] <= *low.rbegin())
                    low.erase(low.find(nums[i - k]));
                else 
                    high.erase(high.find(nums[i - k]));
            }

            // add new num
            low.insert(nums[i]);
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));

            if (high.size() > low.size()) {
                low.insert(*high.begin());
                high.erase(high.begin());
            }

            // get median
            if (i >= k - 1) {
                medians.push_back(low.size() > high.size() ? (double) *low.rbegin() : 0.5 * ((double) (*low.rbegin()) + (double) (*high.begin())));
            }
        }
        return medians;

    }
};