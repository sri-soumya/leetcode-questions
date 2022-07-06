class Solution {
public:
    
    int solve(vector<vector<int>> &a,int i,int j,vector<vector<int>> &dp)
    {
        int m=a.size(),n=a[0].size();
        if(i<0||j<0||i>=m||j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int dy[4]={-1,0,0,1};
        int dx[4]={0,-1,1,0};
        int ans=1;
        for(int k=0;k<4;k++)
        {
            if(i+dy[k]<0||i+dy[k]>=m||j+dx[k]<0||j+dx[k]>=n||a[i+dy[k]][j+dx[k]]<=a[i][j])
                continue;
            ans=max(ans,solve(a,i+dy[k],j+dx[k],dp)+1);
        }
        
        return dp[i][j]=ans;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size();
        
        int ans=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,solve(a,i,j,dp));
            }
        }
        
        return ans;
        
    }
};