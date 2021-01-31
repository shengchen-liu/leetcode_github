/*
array of positive ints candiesCount
candiesCount[i]: # of candies of ith type we have

queries: 2D matrix
    queuries[i] = {T, D, C}

rules:
1. start eating candies on day 0;
2. cannot eaty any candy of type i unless we eat all candies of type i-1
3. must eat >= 1 candy per day 

answer
answer[i]:
    true: => we can eat a candy of type_i, Day_i, without eating > C_i on any day
    false: otherwise

return answer

candiesCount = [7,4,5,3,8]
0  1  2  3  4
7  4  5  3  8

queries:
 Type  D   C
[0,    2,  2]
[4,    2,  4]
[2,    13, 1000000000]

answer[0]:
    we can eat a candy of type-0 on day-2, withot eating > 2 candies on any day
    
** | ** |0 |
00 | 00 | 00 |  => true
answer[1]:
    we can eat a candy of type-4 on day-2, withot eating > 4 candies on any day
eat 4 each day:
0000|0001|1112| => false
eat 1 each day:
0|0|0| => false

step1:
prefix sum on candiesCount
0  1  2  3  4  5
7  4  5  3  8
0  7  11 16 19 27

step2:
traverse query:
    [0, 2, 2]: type-0, day-2, cap: 2
    min_day: eat 2 candies each day  00| 00| ??: day-0
    max_day: eat 1 candy each day: 0 | 0 | ?: day-6
    
    [4, 2, 4]: type-4, day-2, cap: 4
    min_day: eat 4 candies per day,0000|0001|1112| => 19 / 4 = 4
    max_day: eat 1 candy each day => 27 - 1 = 26
*/
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long> preSum(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            preSum[i] = preSum[i - 1] + candiesCount[i - 1];
        }
        
        vector<bool> res;
        for (auto query : queries) {
            int type = query[0];
            int day = query[1];
            int capacity = query[2];
            long maxDay = preSum[type + 1] - 1;  // 7 - 1 = 6
            long minDay = preSum[type] / capacity;  // 0 / 2 = 0
            
            if (day <= maxDay && day >= minDay)
                res.push_back(true);
            else 
                res.push_back(false);
        }
        return res;
    }
};