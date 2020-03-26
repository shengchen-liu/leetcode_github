/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0; // candidate
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) {
                res = i;
            }
        }
        
        // check the people before candidate 
        for (int i = 0; i < res; ++i) {
            if ((knows(res, i)) || (!knows(i, res))) return -1;
        }
        
        // check people after candidate
        for (int i = res + 1; i < n; ++i) {
            if (!knows(i, res)) return -1;
        }
        return res;
    }
};