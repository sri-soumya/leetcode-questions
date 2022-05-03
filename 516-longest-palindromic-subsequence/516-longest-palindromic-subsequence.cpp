class Solution {
public:
    
    int solve(string s,int i,int j,vector<vector<int>> &dp)
    {
        int n=s.length();
        if(i==n+1||j==0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i-1]==s[j-1])
            return dp[i][j]= 1+solve(s,i+1,j-1,dp);
        return dp[i][j]= max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        //return solve(s,1,n,dp);
        
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s[j-1])
                    dp[i][j]=1+dp[i+1][j-1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        
        return dp[1][n];
    }
};