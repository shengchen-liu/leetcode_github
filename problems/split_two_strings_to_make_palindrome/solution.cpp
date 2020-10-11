class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n -1;
        while (i < j) {
            if (s[i] != s[j]) 
                return false;
            ++i;
            --j;
        }
        
        return true;
    }
    
    bool check(string &a, string &b) {
        int i = 0, j = a.size() - 1;
        while (i < j && a[i] == b[j]) {
            ++i;
            --j;
        }
        
        return isPalindrome(a.substr(i, j - i + 1)) ||
            isPalindrome(b.substr(i, j - i + 1));
    }
    
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }

};