/*
 s = "iloveleetcodeabc", 
 words = ["i","love","leetcode","apples"]
i + love + leetcode => iloveleetcode
true

s = "iloveleetcode", 
words = ["apples","i","love","leetcode"]
apples : s (x) => false

i = 0

iloveleetcode    
i                 i
 i                love
    i             leetcode
            i

for word in words:
    if i == s.size():
        return true
    check if word is in s[i to j]:
        if no : return false
return false
    
s: leet
word: leetcode
*/

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.size();  // 1
        int i = 0;
        // for each word
        for (string word : words) {
            if (i >= n)
                return true;
            // word vs s.substring(i, i + word.size())
            if (word != s.substr(i, word.size()))
                return false;
            // move i
            i += word.size(); // 1
        }
        return i == n;
    }
};