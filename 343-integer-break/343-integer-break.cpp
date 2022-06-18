class Solution {
public:
    
    int solve(int n,vector<int> &dp)
    {
        if(n<=1)
            return n;

        if(dp[n]!=-1)
            return dp[n];
        
        int a=0;
        
        for(int i=1;i<n;i++)
        {
            a=max(a,i*solve(n-i,dp));
        }
        
        return dp[n]= max(a,n);
    }
    
    int integerBreak(int n) {
     
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        
        vector<int> dp(n+1,0);
        
        //return solve(n,dp);
        
        dp[0]=0;dp[1]=1;
        
        for(int i=0;i<=n;i++)
        {
            int a=0;
            for(int j=1;j<i;j++)
                a=max(a,j*dp[i-j]);
            dp[i]=max(a,i);
        }
        
        return dp[n];
        
    }
};