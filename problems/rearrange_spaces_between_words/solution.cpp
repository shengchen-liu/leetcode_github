class Solution {
public:
    string reorderSpaces(string text) {
        string res = "";
        stringstream ss(text);
        
        int n = text.size();
        // num of spaces, num of word
        int num_s = 0;
        int num_w = 0;
        for (int i = 0; i < n - 1; ++i) {
            char c = text[i];
            if (c == ' ') ++num_s;
            else {
                if (text[i + 1] == ' ') ++num_w;
            }
        }
        
        if (text[n - 1] != ' ') ++num_w;
        else ++num_s;
        
        // cout << num_w << "," << num_s;
        string word;

        if (num_w == 1) {
            ss >> word;
            res += word;
            while (res.size() < n) {
                res.push_back(' ');
            }
        } else {
            int cnt = num_s / (num_w - 1);
            int rem = num_s % (num_w - 1);

            while (ss >> word) {
                res += word;
                for (int i = 0; i < cnt; ++i) {
                    res.push_back(' ');
                }
            }
            // pop back last spaces
            for (int i = 0; i < cnt; ++i) {
                res.pop_back();
            }        

            if (rem > 0) {
                for (int i = 0; i < rem; ++i){
                    res.push_back(' ');
                }
            }
        }
        

        
        return res;
    }
};