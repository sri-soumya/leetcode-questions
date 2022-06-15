class Solution {
public:
    
    int solve(int n,vector<int> &dp)
    {
        if(n<=2)
            return max(0,n);
        
        int ans=0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        for(int i=1;i<=n;i++)
        {
            ans+=max(1,solve(i-1,dp))*max(1,solve(n-i,dp));
        }
        
        return dp[n]= ans;
    }
    
    int numTrees(int n) {
        
        if(n<=2)
            return n;
        
        vector<int> dp(n+1,0);
        
        //return solve(n,dp);
        
        dp[1]=1;dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i]+=max(1,dp[j-1])*max(1,dp[i-j]);
            }
        }
        
        return dp[n];
    }
};