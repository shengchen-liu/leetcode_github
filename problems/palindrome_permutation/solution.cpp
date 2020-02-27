class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hashmap;
        for (char c : s) {
            ++hashmap[c];
        }
        
        int count = 0;
        for (auto it : hashmap) {
            if (it.second % 2 == 1) ++count;
        }
        if (count > 1) return false;
        return true;
    }
};