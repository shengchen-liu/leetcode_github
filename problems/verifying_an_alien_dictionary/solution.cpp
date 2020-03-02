/**
create a map
mapping[26]
a: 2
b: 3
c: 4
d: 5
e: 6
h: 0
...
z:
**/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mapping(26);
        for (int i = 0; i < 26; ++i) {
            mapping[order[i] - 'a'] = i;
        }
        for (string &word : words) {
            for (char &c : word) {
                c = mapping[ c - 'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};