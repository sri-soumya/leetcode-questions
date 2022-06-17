class Solution {
public:
    
    int solve(vector<int> &a,int t,int i,vector<vector<int>> &dp)
    {
        int n=a.size();
        
        if(!t)
            return 0;
        
        if(i>=n||t<0)
            return 1e8;
        
        if(dp[i][t]!=-1)
            return dp[i][t];
        
        int op1=1+solve(a,t-a[i],i,dp);
        int op2=solve(a,t,i+1,dp);
        
        return dp[i][t]= min(op1,op2);
    }
    
    int coinChange(vector<int>& a, int t) {
        
        int n=a.size();
        
        vector<vector<int>> dp(n,vector<int>(t+1,-1));
        
        
        int c=solve(a,t,0,dp);
        
        if(c>t)
            return -1;
        return c;    
        
    }
};