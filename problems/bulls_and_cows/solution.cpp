/**
bulls: digit and position
cows: digit (Y) AND position(N)

bulls:
for i in range(n):
    secret[i] == guess[i] ? yes : no
    else: 
        update buckets
**/
class Solution {
public:
    string getHint(string secret, string guess) {
        int m[256] = {0}, bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++bulls;
            else {
                if (m[secret[i]]++ < 0) ++cows;
                if (m[guess[i]]-- > 0) ++cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};