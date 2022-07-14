class Solution {
public:
    
    void dfs(vector<vector<int>> &a,int i,int j)
    {
        int n=a.size(),m=a[0].size();
        if(i<0||j<0||i>=n||j>=m||a[i][j]!=1)
            return;
        
        a[i][j]=2;
        dfs(a,i+1,j);
        dfs(a,i-1,j);
        dfs(a,i,j-1);
        dfs(a,i,j+1);
    }
    
    int numEnclaves(vector<vector<int>>& a) {
        
        int n=a.size(),m=a[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(a[i][0]==1)
                dfs(a,i,0);
            if(a[i][m-1]==1)
                dfs(a,i,m-1);
        }
        
        for(int i=0;i<m;i++)
        {
            if(a[0][i]==1)
                dfs(a,0,i);
            if(a[n-1][i]==1)
                dfs(a,n-1,i);
        }
        
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(a[i][j]==1)
                    c++;
        }
        
        return c;
    }
};