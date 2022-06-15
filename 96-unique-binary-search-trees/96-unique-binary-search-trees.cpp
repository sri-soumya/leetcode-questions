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
        
        return ans;
    }
    
    int numTrees(int n) {
        
        vector<int> dp(n+1,-1);
        
        return solve(n,dp);
    }
};