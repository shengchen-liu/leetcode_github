/*                                  next_warmer   st
 0   1   2   3   4   5   6   7
[73, 74, 75, 71, 69, 72, 76, 73]
                                                  []                  
                              i     0             [(73, 7)]
                          i         0             [(76, 6)]
                     i              1             [(72, 5), (76, 6)]
                 i                  1             [(69, 4), (72, 5), (76, 6)]
              i                     2             [(71, 3), (72, 5), (76, 6)]
          i                         4             [(75, 2), (76, 6)] 
      i                             1             [(74, 1), (75, 2), (76, 6)] 
 i                                  1             [(73, 0), (74, 1), (75, 2), (76, 6)]     
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        stack<pair<int, int>> st;
        // build stack
        for (int i = n - 1; i >= 0; --i) {
            int cur = T[i];
            while (!st.empty() && st.top().first <= cur) {
                st.pop();
            }
            if (st.empty()){
                res[i] = 0;
            } else {
                res[i] = st.top().second - i;
            }
            st.push({cur, i});
        }
        return res;
    }
};