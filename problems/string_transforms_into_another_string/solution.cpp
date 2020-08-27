class Solution {
public:
    bool canConvert(string str1, string str2) {
       if (str1 == str2) return true;
        unordered_map<char, char> m;
        for (int i = 0; i < str1.size(); ++i) {
            if (m[str1[i]] != NULL && m[str1[i]] != str2[i]) 
                return false;
            m[str1[i]] = str2[i];
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};