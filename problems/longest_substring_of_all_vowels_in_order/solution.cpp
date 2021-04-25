class Solution {
public:
    int f(char ch) {
        if(ch == 'a') {
            return 0;
        } else if(ch == 'e') {
            return 1;
        } else if(ch == 'i') {
            return 2;
        } else if(ch == 'o') {
            return 3;
        } else {
            return 4; 
        }
    }
    int longestBeautifulSubstring(string word) {
        vector<int> b(5);
        vector<int> e(5);
        int ret = 0; 
        int begin = -1;
        int cur = -1;
        for(int i = 0;i<word.size();i++) {
            int k = f(word[i]);
            if(k > cur + 1 || k < cur) {
                if(k == 0) {
                    begin = i - 1; 
                    cur = 0;
                } else {
                    begin = i; 
                    cur = -1; 
                }
                continue; 
            }
            cur = k; 
            if(cur == 4) {
                ret = max(ret,i-begin);
            }
        }
        return ret; 
    }
};