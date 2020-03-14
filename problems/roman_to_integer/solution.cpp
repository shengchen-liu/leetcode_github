/**
MCMXCIV
1000 + (-100 + 1000) + (-10 + 100) + (-1 + 5)
Build an order
**/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashmap;
        hashmap['I'] = 1;
        hashmap['V'] = 5;
        hashmap['X'] = 10;
        hashmap['L'] = 50;
        hashmap['C'] = 100;
        hashmap['D'] = 500;
        hashmap['M'] = 1000;       
        
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int val = hashmap[s[i]]; // 1000
            if (i == s.size() - 1 || val >= hashmap[s[i + 1]]) {
                res += val;
            }
            else res -= val;
        }
        return res;
    }
};