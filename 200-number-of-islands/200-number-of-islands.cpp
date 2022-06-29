class Solution {
public:
    
    void dfs(vector<vector<char>>& a,int i,int j)
    {
        
        int m=a.size(),n=a[0].size(),c=0;
        
        if(i<0||i>=m||j<0||j>=n||a[i][j]=='0')
            return;
        
        a[i][j]='0';
        
        dfs(a,i+1,j);
        dfs(a,i-1,j);
        dfs(a,i,j+1);
        dfs(a,i,j-1);
        
        
    }
    
    int numIslands(vector<vector<char>>& a) {
        
        int m=a.size(),n=a[0].size(),c=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='0')
                    continue;
                c++;
                dfs(a,i,j);
            }
        }
        return c;
        
    }
};