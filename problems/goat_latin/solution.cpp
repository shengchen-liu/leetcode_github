/**
1. a word begins with a vowel => append "ma" to the end of the word {a, e, i, o, u}
2.  a word begins with a consonant =>  remove the first letter and append it to the end, then add "ma".
3. Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.

eg: I speak Goat Latin
Ima, a
peaksma, aa
oatGma + aaa
atinLma + aaaa

iterate each word
apply rules to each word
**/
class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string res;
        string t;
        int cnt = 1;
        istringstream ss(S);
        while (ss >> t) {
            res += ' ' + (vowel.count(t[0]) ? t : t.substr(1) + t[0]) + "ma" + string(cnt, 'a');
            ++cnt;
        }
        return res.substr(1);
    }
};