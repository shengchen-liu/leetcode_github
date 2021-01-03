/*
The number at the ith position is divisible by i.
a[i] % (i) == 0

i is divisible by the number at the ith position.
(i) % a[i] == 0

vector<int> a(n + 1)

n = 1

1: 1

n = 2
1 : 1
2 : 2

1 : 2
2 : 1

n = 3
1 : 1
2 : 2
3 : 3


*/
class Solution {
public:
    int countArrangement(int n) {
        vector<bool> visited(n + 1);
        int cnt = 0;
        dfs(n, 1, visited, cnt);
        
        return cnt;
    }
    
    void dfs(int n, int pos, vector<bool> &visited, int &cnt) {
        // termination
        if (pos > n)
            ++cnt;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)){
                visited[i] = true;
                dfs(n, pos + 1, visited, cnt);
                visited[i] =  false;
            }
        }
    }
};