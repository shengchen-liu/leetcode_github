/**
hashset
l:1
e:3
t:1
c:1
o:1
d:1


**/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        for (char c : s) {
            if (!hashmap.count(c)) hashmap[c] = 1;
            else {
                ++hashmap[c];
            }
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (hashmap[s[i]] == 1) return i;
        }
        return -1;
    }
};