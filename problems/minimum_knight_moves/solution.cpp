class Solution {
public:
int dfs(int x, int y, unordered_map<string, int> &dp)
{
if (x > y) swap(x, y);
string key=to_string(x)+","+to_string(y);
if(dp.count(key))
return dp[key];
dp[key]= min(dfs(abs(x-2),abs(y-1),dp),dfs(abs(x-1),abs(y-2),dp))+1;
return dp[key];
}

int minKnightMoves(int x, int y) 
{
    unordered_map<string, int> dp ={ 
                                    {"0,0", 0},
                                    {"0,1", 3},
                                    {"0,2", 2},
                                    {"1,1", 2},
                                    {"1,2", 1},
                                    {"2,2", 4}
                                  };
     return dfs(abs(x),abs(y),dp);
}
};