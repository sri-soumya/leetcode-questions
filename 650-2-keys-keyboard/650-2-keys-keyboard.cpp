class Solution {
public:
    
    int solve(int i,int j,int n,vector<vector<int>> &dp)
    {
        if(i==n)
            return 0;
        // if(i>n)
        //     return 1e7;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int op1=1e7,op2=1e7;
        
        //copy
        //if(i>j)
            op1=solve(i,i,n,dp)+1;
        //paste
        if(j&&i+j<=n)
            op2=solve(i+j,j,n,dp)+1;
        
        return dp[i][j]= min(op1,op2);
        
    }
    
    int minSteps(int n) {
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        //return solve(1,0,n,dp);
        
        for(int i=n-1;i>=1;i--)
        {
            for(int j=n;j>=0;j--)
            {
                int op1=1e7,op2=1e7;
                if(i>j)
                    op1=dp[i][i]+1;
                if(j&&i+j<=n)
                    op2=dp[i+j][j]+1;
                
                dp[i][j]=min(op1,op2);
            }
        }
        
        return dp[1][0];
        
    }
};