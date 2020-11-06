class Solution {
public:
    int maxPower(string s) {
        size_t max = 1;
        size_t curr = 1;
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) curr++;
            else {
                if (curr > max) max = curr;
                curr = 1;
            }
        }
        if (curr > max) max = curr; // edge case
        return max;
    }
};