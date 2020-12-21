class Solution {
public:
    bool canConvert(string str1, string str2) {
       if (str1 == str2) return true;
        unordered_map<char, char> m;
        for (int i = 0; i < str1.size(); ++i) {
            char a = str1[i];
            char b = str2[i];
            if (m[a] != NULL && m[a] != b) 
                return false;
            m[a] = b;
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};