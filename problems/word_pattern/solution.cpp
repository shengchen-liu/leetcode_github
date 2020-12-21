/*
abba  vs dog cat cat dog
split by space
char : word
word : char

a : dog
b : cat

dog : a
cat : b
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i >= n) continue;
            if (m.count(pattern[i])) {
                if (m[pattern[i]] != word) return false;
            } else {
                for (auto a : m) {
                    if (a.second == word) return false;
                }
                m[pattern[i]] = word;
            }
        }
        return i == n;
    }
};