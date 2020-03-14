class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(); // 2
        int n = b.size(); // 1
        int i = m - 1; // 1
        int j = n - 1; //0
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0) {
            int p = i >= 0 ? a[i] - '0' : 0;
            int q = j >= 0 ? b[j] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
            --i;
            --j;
        }
        return carry == 1 ? res = "1" + res: res;
    }
};