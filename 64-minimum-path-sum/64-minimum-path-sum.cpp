class Solution {
public:
    
    int solve(vector<vector<int>> a,int m,int n,vector<vector<int>> &dp)
    {
        if(m<0||n<0)
            return INT_MAX;
        if(m==0&&n==0)
            return a[m][n];
        if(dp[m][n]!=-1)
            return dp[m][n];
        return dp[m][n]=a[m][n]+min(solve(a,m-1,n,dp),solve(a,m,n-1,dp));
    }
    
    int minPathSum(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        //return solve(a,m-1,n-1,dp);
        dp[0][0]=a[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                    continue;
                int c1=INT_MAX,c2=INT_MAX;
                if(i-1>=0)
                    c1=dp[i-1][j];
                if(j-1>=0)
                    c2=dp[i][j-1];
                dp[i][j]=min(c1,c2)+a[i][j];
            }
        }
        
        return dp[m-1][n-1];
    }
};