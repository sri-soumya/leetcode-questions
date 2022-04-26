class Solution {
public:
    
    int solve(vector<vector<int>> a,int i,int j,vector<vector<int>> &dp)
    {
        int n=a.size();
        if(i>=n||j>=n||j<0)
            return INT_MAX;
        if(i==n-1)
            return a[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=a[i][j]+min(solve(a,i+1,j,dp),min(solve(a,i+1,j-1,dp),solve(a,i+1,j+1,dp)));
    }
    
    int minFallingPathSum(vector<vector<int>>& a) {
        int m=INT_MAX;
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++)
        // {
        //     m=min(m,solve(a,0,i,dp));
        // }
        
        dp[n-1]=a[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int c1=dp[i+1][j],c2=INT_MAX,c3=INT_MAX;
                if(j-1>=0)
                    c2=dp[i+1][j-1];
                if(j+1<n)
                    c3=dp[i+1][j+1];
                
                dp[i][j]=min(c1,min(c2,c3))+a[i][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            m=min(m,dp[0][i]);
        }
        
        return m;
    }
};