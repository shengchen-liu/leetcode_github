/*
abccba
replace 1 char
smallest, not a palindrome


*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n <= 1)
            return "";
        string res = palindrome;
        
        for (int i = 0; i < n / 2; ++i) {
            if (palindrome[i] != 'a'){
                res[i] = 'a';
                return res;
            }
        }
        res[n - 1] = 'b';
        return res;
    }
};