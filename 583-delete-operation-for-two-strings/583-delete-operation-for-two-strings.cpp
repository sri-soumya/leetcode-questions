class Solution {
public:
    
    int solve(string &a,string &b,int i,int j,vector<vector<int>> &dp)
    {
        if(i==0||j==0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i-1]==b[j-1])
            return dp[i][j]= 1+solve(a,b,i-1,j-1,dp);
        return dp[i][j]= max(solve(a,b,i-1,j,dp),solve(a,b,i,j-1,dp));
    }
    
    int minDistance(string a, string b) {
        int n=a.length(),m=b.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return m+n-2*solve(a,b,n,m,dp);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n+m-2*dp[n][m];
    }
};