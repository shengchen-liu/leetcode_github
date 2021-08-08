class Solution {
public:
    int minSwaps(string s) {
       int close = 0;
       int maxClose = 0;
        
        for (auto c : s){
            if (c == '[')
                close -= 1;
            else
                close += 1;
            maxClose = max(close, maxClose);
        }
        return (maxClose + 1) / 2;

    }
};