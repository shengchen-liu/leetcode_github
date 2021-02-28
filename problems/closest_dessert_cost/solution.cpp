/*
desert: base, toppings
n bases, m toppings
base: must exactly have 1 base 
toppings: choose 1, more or 0 toppings 
          for the same topping, we can choose <= 2
each base, topping has a cost
target cost, find the closest possbile choice to match the target

example
base: [1, 7]
topping: [3, 4]
target: 10

base: 7
topping: 1*3 + 0*4 = 3
total: 10

example2:
baseCosts = [2,3], 
toppingCosts = [4,5,100], 
target = 18

base: 3
toppings: 4 + 5 + 5 = 14
total: 17

idea 1
toppings: combination
3^10

idea 2:
backtracking problem->combination 

0  1  2
4, 5, 100 
dfs(cur_idx, cur_cost, target):
    // termination
    compare cur_cost vs target, check if they are the closest
    
    // recursion
    for (i =  cur_idx, i < , ++i) 
        1. pick 0 of topping[i]
            dfs(i + 1, cur_cost, target)
        2. pick 1 of topping[i]
            dfs(i + 1, cur_cost + toppoing[i], target)
        3. pick 2 of topping[i]
            dfs(i + 1, cur_cost + 2 * toppoing[i], target)

*/
class Solution {
public:
    void dfs(int idx, int curCost, int target, int &res, int &minDiff, const vector<int>& toppingCosts) {
        // termination
        int m = toppingCosts.size();
        if (curCost == target) {
            minDiff = 0;
            res = curCost;
            return;
        }
        if (curCost > target) {
            if (curCost - target < minDiff) {
                res = curCost;
                minDiff = curCost - target;
            }
            return;
        } else{  // curCost < target
            if (target - curCost < minDiff) {
                res = curCost;
                minDiff = target - curCost;
            }
        }
        
        if (idx == m)
            return;
        
        // recursion
        for (int i = idx; i < m; ++i) {
            // 3 choices
            // 1. 0
            dfs(i + 1, curCost, target, res, minDiff, toppingCosts);
            
            // 2. 1 topping
            dfs(i + 1, curCost + toppingCosts[i], target, res, minDiff, toppingCosts);
            
            // 3. 2 toppings
            dfs(i + 1, curCost + 2 * toppingCosts[i], target, res, minDiff, toppingCosts);
        }
        
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size();
        int res = 0;
        int minDiff = INT_MAX;
        
        // traverse each base 
        for (int base : baseCosts) {
            dfs(0, base, target, res, minDiff, toppingCosts);
        }
        
        return res;
    }
};