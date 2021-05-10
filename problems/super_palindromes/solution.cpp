class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int ans = 9 >= stol(left) && 9 <= stol(right) ? 1 : 0;
        for (int i = 1; i < 19684; i++) {
            string num = base3(i);
            if (isPal(num)) {
                long square = stol(num) * stol(num);
                if (square > stol(right)) return ans;
                if (square >= stol(left) && isPal(to_string(square))) ans++;
            }
        }
        return ans;
    }
    
    string base3(int n, string num="") {
        if (!n) return num;
        div_t divres = div(n, 3);
        return base3(divres.quot, (char)(divres.rem + 48) + num);
    }
    
    bool isPal(string str) {
        for (int i = 0, j = str.length() - 1; i < j; i++, j--)
            if (str[i] != str[j]) return false;
        return true;
    }
};