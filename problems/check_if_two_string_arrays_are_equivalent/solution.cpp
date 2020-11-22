/*
2 string arrays. word1, word2
compare these two arrays
word1 = ["ab", "c"], word2 = ["a", "bc"]
generate string based on the array
string1 = "ab" + "c" = "abc"
string2 = "a" + "bc" = "abc"
string1 vs string2 =? equal

*/


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        // constrcut two strings
        for (string s : word1) {
            str1 += s;
        }
        
        for (string s : word2) {
            str2 += s;
        }
        
        // compare
        return str1 == str2;
        
    }
};