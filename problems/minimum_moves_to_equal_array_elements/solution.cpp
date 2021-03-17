class Solution {
public:
    int minMoves(vector<int>& nums) {
         int minV = *min_element(begin(nums), end(nums));
        return accumulate(begin(nums), end(nums), 0, [minV](long a, int b){return a - minV + b;});
    }
};