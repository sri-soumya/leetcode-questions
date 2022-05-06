class Solution {
public:
    int maxProfit(int m, vector<int>& a) {
        
        int n=a.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(m+1,0)));
        //return solve(a,0,1,2,dp);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int f=0;f<2;f++)
            {
                for(int k=1;k<=m;k++)
                {
                    if(f)
                    {
                        dp[i][f][k]=max(-a[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else
                    {
                        dp[i][f][k]=max(a[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                }
            }
        }
        
        return dp[0][1][m];
        
    }
};