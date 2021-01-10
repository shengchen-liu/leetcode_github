/*
[1,2,3], first = 1
encoded[i] = arr[i] XOR arr[i + 1]

1 xor arr[1] = 1
*/
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> res(n + 1);
        res[0] = first;
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        
        return res;
    }
};