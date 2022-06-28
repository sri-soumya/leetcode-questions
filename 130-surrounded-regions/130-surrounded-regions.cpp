class Solution {
public:
    
    void dfs(vector<vector<char>> &a,int i,int j)
    {
        int m=a.size(),n=a[0].size();
        if(i<0||i>=m||j<0||j>=n||a[i][j]=='X'||a[i][j]=='#')
            return;
        
        a[i][j]='#';
        dfs(a,i-1,j);
        dfs(a,i,j-1);
        dfs(a,i,j+1);
        dfs(a,i+1,j);
        
    }
    
    
    void solve(vector<vector<char>>& a) {
        
        int m=a.size(),n=a[0].size();
        
        for(int i=0;i<m;i++)
        {
            if(a[i][0]=='O')
                dfs(a,i,0);
            if(a[i][n-1]=='O')
                dfs(a,i,n-1);
        }
        
        for(int j=0;j<n;j++)
        {
            if(a[0][j]=='O')
                dfs(a,0,j);
            if(a[m-1][j]=='O')
                dfs(a,m-1,j);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='#')
                    a[i][j]='O';
                else if(a[i][j]=='O')
                    a[i][j]='X';
            }
        }
        
    }
};