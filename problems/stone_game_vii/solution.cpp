/*
 stones = [5,3,1,4,2]
 A, B
 1. remove start stone
 score = sum(stoned[start + 1] to stone[end])
 2. remve end stone
 score = sume(stone[start] to stone[end-1])
 
 prefix sum
         5, 3,1,  4,  2
 preSum  5, 8, 9, 13, 15
 
 Obs2:
 Alice: return max positive value => diff(A.score - B.score) is max
A's diff = B's diff + curScore

 Bob: return max negative value => diff(A.score - B.score) is min
 B's diff = A'diff - curScore (negatvie)
 
3.optimaztion
momorization
 
*/
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        // prefix sum
        vector<int> preSum(n + 1, 0); // [0 0 0 0 0 0]
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + stones[i];
        }
        
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        
        // recursion
        int res = 0;
        res = dfs(preSum, 0, n - 1, true, memo); // bool: it's Alice's turn
        return abs(res);
    }
    
    int dfs(vector<int> &preSum, int start, int end, bool alice, vector<vector<int>> &memo) {
        // termination
        if (start == end)
            return 0;
        
        // recursion
        // memo
        if (memo[start][end] < INT_MAX) {
            return memo[start][end];
        }
        
        int diff;
        // score: remove start, remove end
        int scoreRemoveFirst = preSum[end + 1] - preSum[start + 1];
        int scoreRemoveEnd = preSum[end] - preSum[start];
        
        // who's the player
        if (alice){
            //  Alice: return max positive value => diff(A.score - B.score) is max
            diff = max(dfs(preSum, start + 1, end, !alice, memo) + scoreRemoveFirst,
                       dfs(preSum, start, end - 1, !alice, memo) + scoreRemoveEnd);
        } else {
            // Bob: return max negative value => diff(A.score - B.score) is min 
            diff = min(dfs(preSum, start + 1, end, !alice, memo) - scoreRemoveFirst,
                       dfs(preSum, start, end - 1, !alice, memo) - scoreRemoveEnd);
        }
        memo[start][end] = diff;
        
        return diff;
        
    }
};