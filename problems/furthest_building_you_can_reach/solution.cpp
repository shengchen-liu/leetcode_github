/*
heights
bricks
ladders
1. currentBuild >= next Build: move one
2. curBuild < next Buil: 
  1) use ladder
  2) use bricks  # of bricks == diff(curBuild, nextBuild)

heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
4,2,7,6,9,14,12     bricks_rem   ladd_rem
i                   5            1 
  i                 5            1
    i               0            1
      i             0            1
        i           0            0
           x    
idx: 4

dfs(idx, rem_b, rem_l):
    at this current, keep updating the max building that we can reach
    
*/
class Solution {
public:
    int res = 0;
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // update on heights
        for (int i = 0; i < heights.size() - 1; ++i) {
            // 1. cureBuil >= next building
            // 2. cureBuil < next building
            heights[i] = max(0, heights[i + 1] - heights[i]);
        }
        // move to the next step 
        heights.back() = 0;
                
        dfs(heights, bricks, ladders, 0);
        return res;
    }

    void dfs(vector<int>& heights, int B, int L, int start) {
        // termination
        if (res == heights.size() - 1) return;
        if (start == heights.size() - 1) {
            res = heights.size() - 1;
            return;
        }
        
        // recursion
        for (int i = start; i < heights.size(); ++i) {
            res = max(res, i);
            if (heights[i] == 0) continue;
            if (B >= heights[i]) {// use bricks
                dfs(heights, B - heights[i], L, i + 1);
            }
            if (L > 0) {
                // use ladder
                dfs(heights, B, L - 1, i + 1);
            }
            break;
        }

    }
};