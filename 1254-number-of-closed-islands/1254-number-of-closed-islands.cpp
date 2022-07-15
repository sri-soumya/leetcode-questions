class Solution {
public:
    
    void dfs(vector<vector<int>> &a,int i,int j)
    {
        
        int m=a.size(),n=a[0].size();
        
        if(i<0||j<0||i>=m||j>=n||a[i][j]!=0)
            return;
        
        a[i][j]=2;
        
        dfs(a,i-1,j);
        dfs(a,i+1,j);
        dfs(a,i,j-1);
        dfs(a,i,j+1);
    }
    
    int closedIsland(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size();
        
        int c=0;
        
        for(int i=0;i<m;i++)
        {
            if(a[i][0]==0)
                dfs(a,i,0);
            if(a[i][n-1]==0)
                dfs(a,i,n-1);
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[0][i]==0)
                dfs(a,0,i);
            if(a[m-1][i]==0)
                dfs(a,m-1,i);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==0)
                {
                    c++;
                    dfs(a,i,j);
                }
            }
        }
        
        return c;
        
    }
};