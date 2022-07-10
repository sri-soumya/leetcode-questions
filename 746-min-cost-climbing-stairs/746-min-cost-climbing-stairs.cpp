class Solution {
public:
    
    int solve(vector<int> &a,int i,vector<int> &dp)
    {
        int n=a.size();
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i]= min(solve(a,i+1,dp),solve(a,i+2,dp))+a[i];
    }
    
    int minCostClimbingStairs(vector<int>& a) {
        
        int n=a.size();
        
        //return min(solve(a,0),solve(a,1));
        vector<int> dp(n+2,0);
        solve(a,0,dp);
        
        //return min(dp[0],dp[1]);
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=min(dp[i+1],dp[i+2])+a[i];
        }
        
        return min(dp[0],dp[1]);
    }
};