class Solution {
public:
    
    int solve(vector<vector<int>>& a,int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>m||j>n||a[i][j]==1)
            return 0;
        if(i==m&&j==n)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=solve(a,i+1,j,m,n,dp)+solve(a,i,j+1,m,n,dp);
    }

    
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
    
        //return solve(a,0,0,m-1,n-1,dp);\
        
        if(a[m-1][n-1]==1||a[0][0]==1)
            return 0;
        dp[m-1][n-1]=1;
        for(int i=m-2;i>=0;i--)
        {
            if(a[i][n-1]==1)
                dp[i][n-1]=0;
            else
                dp[i][n-1]=dp[i+1][n-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(a[m-1][i]==1)
                dp[m-1][i]=0;
            else
                dp[m-1][i]=dp[m-1][i+1];
        }
        
        for(int j=n-2;j>=0;j--)
        {
            for(int i=m-2;i>=0;i--)
            {
                if(a[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};