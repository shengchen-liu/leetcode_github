class Solution {
public:
int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long int>>pos(m,vector<long long int>(n,0));
        vector<vector<long long int>>neg(m,vector<long long int>(n,0));
         int i,j;
        long long int a,b;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                     pos[i][j]=grid[i][j];
                     neg[i][j]=grid[i][j];
                    continue;
                }
                if(i==0)
                {
                     a=pos[i][j-1];
                     b=neg[i][j-1];
                     a=(a*grid[i][j]);
                    b=(b*grid[i][j]);
                    pos[i][j]=max(a,b);
                    neg[i][j]=min(a,b);
                    
                }
                else if(j==0)
                {
                     a=pos[i-1][j];
                     b=neg[i-1][j];
                     a=(a*grid[i][j]);
                    b=(b*grid[i][j]);
                    pos[i][j]=max(a,b);
                    neg[i][j]=min(a,b);
                }
                else
                {
                     a=pos[i][j-1];
                    b=neg[i][j-1];
                     a=(a*grid[i][j]);
                    b=(b*grid[i][j]);
                    pos[i][j]=max(a,b);
                    neg[i][j]=min(a,b);
                     a=pos[i-1][j];
                     b=neg[i-1][j];
                    a=(a*grid[i][j]);
                    b=(b*grid[i][j]);
                    pos[i][j]=max(a,max(pos[i][j],b));
                    neg[i][j]=min(a,min(neg[i][j],b));
                }
            }
        }
        if(pos[m-1][n-1]<0)return -1;
        return pos[m-1][n-1]%1000000007;
    }
};