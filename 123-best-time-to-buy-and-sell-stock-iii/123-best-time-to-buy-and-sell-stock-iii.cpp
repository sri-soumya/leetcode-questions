class Solution {
public:
    
    int solve(vector<int> &a,int i,int f,int k,vector<vector<vector<int>>> &dp)
    {
        int n=a.size();
        if(!k)
            return 0;
        if(i==n)
            return 0;
        int p=0;
        
        if(dp[i][f][k]!=-1)
            return dp[i][f][k];
        
        if(f)
        {
            p=max(-a[i]+solve(a,i+1,0,k,dp),solve(a,i+1,1,k,dp));
        }
        else
            p=max(a[i]+solve(a,i+1,1,k-1,dp),solve(a,i+1,0,k,dp));
        
        return dp[i][f][k]= p;
    }
    
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(a,0,1,2,dp);
    }
};