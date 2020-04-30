class Solution {
public:
    int countElements(vector<int>& arr) {
        // sort 
        sort(arr.begin(), arr.end());
        int n = arr.size();
        //diff
        vector<int> diff;
        for (int i = 0; i < n - 1; ++i) {
            diff.push_back(arr[i + 1] - arr[i]);
        }
        
        int res = 0;
        
        for (int i = n - 2; i >= 0; --i) {
            if (diff[i] == 1) {
                int j = i - 1;
                int cnt = 1;
                while (j >= 0) {
                    if (diff[j--] == 0) ++cnt;
                    else break;
                }
                res += cnt;
            }
        }
        return res;
    }
};