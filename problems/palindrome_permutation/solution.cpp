/*
num of odd digits <= 1
a: 2
b: 1

*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        
        int cnt = 0;
        for (auto a : m) {
            if (a.second % 2 == 1)
                ++cnt;
            if (cnt > 1)
                return false;
        }
    
        return true;
    }
};