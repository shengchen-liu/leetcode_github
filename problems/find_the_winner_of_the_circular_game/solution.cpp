/*
n friends sitting in a circle
start from friend 1
count next k friends including the starting friend

simulat the game
keep playing until only 1 friend remaining

vector of size n
each round:
    start from current 
    rotate k steps
    update current
    eliminate the current friend
    
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> friends(n, true);
        
        int current = 0;
        int cnt = n;  // # of friends remaining
        while (cnt > 1) {
            for (int step  = 0; step < k; ++step, ++current) {
                while (!friends[current % n])
                    ++current;   // skip deleted friend
            }
            friends[(current - 1) % n] = false;
            --cnt;
        }
        
        current = 0;
        while (!friends[current])
            ++current;
        return current + 1;
    }
};