/*
input: array of words
1. find two words that do not share common letters
2. find max val of len(w1) * len(w2)

"abcw","baz","foo","bar","xtfn","abcdef"
a: abcw, baz, bar, abcdef
b: abcw, baz, bar, abcdef
c: abcw, abcdef
z: baz
f: foo, xtfn, abcdef
o: foo
r: bar
x: xtfn
t: xtfn
n: xtfn
e: abcdef

pick w1 abcw
for each other w2:
    if no_share(w1, w2):
        update max_prod
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> mask(words.size(), 0);
        // bit mask
        // abcw:[0001...00000111]
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
        }
        
        // compare
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (!(mask[i] & mask[j])){
                    int len1 = words[i].size();
                    int len2 = words[j].size();
                    res = max(res, len1 * len2);
                }
            }
        }
        return res;
    }
};