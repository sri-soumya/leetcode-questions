class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        
        int n=a.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        //return solve(a,0,1,dp);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int f=0;f<=1;f++)
            {
                if(f)
                    dp[i][f]=max(-a[i]+dp[i+1][0]-fee,dp[i+1][1]);
                else
                    dp[i][f]=max(a[i]+dp[i+1][1],dp[i+1][0]);
            }
        }
        
        return dp[0][1];
        
    }
};