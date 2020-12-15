/*
[2,7,9,4,4] M = 1
tak in the first x remaining piles, where 1 <= x <= 2M
M = max(M, X)
stop until all stones are taken
return max stones Alice can get

                        [2,7,9,4,4] M:1
                     /                    \
A:            [7,9,4,4]M:1              [9,4,4]M:2
               /   \                       |
B:       [9,4,4]M:1 [4,4]M:2               -17
           /\         |        
A: [4,4]M:1 [4]M:2    8        
              
B: -8        -4           

prefix sum

*/
class Solution {
public:
  int stoneGameII(vector<int>& piles) {
    const int n = piles.size();
    unordered_map<int, int> cache;
    // Maximum diff starting from piles[s] given M.
    function<int(int, int)> solve = [&](int s, int M) {
      if (s >= n) return 0;
      const int key = (s << 8) | M;
      if (cache.count(key)) return cache[key];
      int best = INT_MIN;
      int curr = 0;
      for (int x = 1; x <= 2 * M; ++x) {
        if (s + x > n) break;
        curr += piles[s + x - 1];
        best = max(best, curr - solve(s + x, max(x, M)));
      }
      return cache[key] = best;
    };    
    int total = accumulate(begin(piles), end(piles), 0);
    return  (total + solve(0, 1)) / 2;
  }
};