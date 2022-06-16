class Solution {
public:
    
    int solve(vector<int> &a,int i,int n,vector<int> &dp)
    {
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i]= max(a[i]+solve(a,i+2,n,dp),solve(a,i+1,n,dp));
    }
    
    int rob(vector<int>& a) {
    
        int n=a.size();
        if(n==1)
            return a[0];
        vector<int> dp1(n,-1),dp2(n,-1);
        
        return max(solve(a,0,n-1,dp1),solve(a,1,n,dp2));
        
    }
};