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
    
    int coinChange(vector<int>& a, int k) {
        
        int n=a.size();
        
        vector<vector<int>> dp(n,vector<int>(k+1,0));
//         int c=solve(a,k,0,dp);
        
//         if(c>t)
//             return -1;
//         return c;    
        
        for(int i=n-1;i>=0;i--)
        {
            for(int t=1;t<=k;t++)
            {
                int op1=1e8,op2=1e8;
                if(t-a[i]>=0)
                    op1=dp[i][t-a[i]]+1;
                if(i+1<n)
                    op2=dp[i+1][t];
                
                dp[i][t]=min(op1,op2);
            }
        }
        
        if(dp[0][k]>k)
            return -1;
        
        return dp[0][k];
        
        
    }
};