class Solution {
public:
    
    int solve(vector<int> a,int i,int f,vector<vector<int>> &dp)
    {
        int n=a.size();
        if(i>=n)
            return 0;
        
        if(dp[i][f]!=-1)
            return dp[i][f];
        
        int p=0;
        if(f)
            p=max(-a[i]+solve(a,i+1,0,dp),solve(a,i+1,1,dp));
        else
            p=max(a[i]+solve(a,i+2,1,dp),solve(a,i+1,0,dp));
        
        return dp[i][f]= p;
    }
    
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        
        //int n=a.size();
        return solve(a,0,1,dp);
        
    }
};