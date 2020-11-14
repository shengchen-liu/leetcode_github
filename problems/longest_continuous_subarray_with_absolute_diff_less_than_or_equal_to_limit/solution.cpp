/*
8, 2, 4, 7          max_diff    max_size  maxHeap   minHeap
ij                  0           1         8         8
i  j                6           1         8,2       2,8
   ij               0           1         2         2         
   i  j             2           2         4,2       2,3 
   i     j          5           2         7, 4, 2   2, 4, 7  
      i  j          3           2         7, 4      4, 7
      
max_val, min_val
*/
class Solution {
public:
        int longestSubarray(vector<int>& A, int limit) {
        deque<int> maxd, mind;
        int i = 0, j;
        for (j = 0; j < A.size(); ++j) {
            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
            maxd.push_back(A[j]);
            mind.push_back(A[j]);
            if (maxd.front() - mind.front() > limit) {
                if (maxd.front() == A[i]) maxd.pop_front();
                if (mind.front() == A[i]) mind.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};