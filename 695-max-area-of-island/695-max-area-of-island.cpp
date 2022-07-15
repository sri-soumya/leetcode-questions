class Solution {
public:
    
    int dfs(vector<vector<int>> &a,int i,int j)
    {
        int m=a.size(),n=a[0].size();
        
        if(i<0||j<0||i>=m||j>=n||a[i][j]==0)
            return 0;
        
        a[i][j]=0;
        
        return dfs(a,i+1,j)+dfs(a,i-1,j)+dfs(a,i,j-1)+dfs(a,i,j+1)+1;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size();
        
        int ans=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j])
                    ans=max(ans,dfs(a,i,j));
            }
        }
        
        return ans;
        
    }
};