/*
[8,2,4,7], limit=4
subarray.
1. non-empty
2. abs diff betw any two elements <= limit
return the longest subarray

limit: 5
10,   1,    2,    4,    7,    2     len  valid? multiset
i,j                                 1    T       
i     j                             1    F
      i,j                           1    t
      i     j                       2    T
      i           j                 3    T
      i                 j           3    F
            i           j           3    T
            i                 j     4    T

idx j:
opt1:
    for k = [i, j-1]
        abs_diff(k, j) <= limit
opt2:
    multiset.begin - multiset.last <= limit => True
    else False

sliding windown
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