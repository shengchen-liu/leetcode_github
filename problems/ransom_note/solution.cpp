/*
ransom note: "aa"
string: "aab"
hashmap_magazine:
a : 2
b : 1

for each letter in ransom note:
    check if hashmap contains this letter
        if yes, update
        else return false
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for (char l : magazine) {
            ++mag[l];
        }
        
        for (char c : ransomNote) {
            if (mag.count(c)) {
                if (mag[c] == 1) {
                    mag.erase(c);
                } else {
                    --mag[c];
                }
            } else {
                return false;
            }
        }
        return true;
    }
};