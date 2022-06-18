class Solution {
public:
    
    
    bool perfect(int n)
    {
        int x=ceil(sqrt(n));
        return x*x==n;
    }
    
    int solve(int n,vector<int> &dp)
    {
        if(!n)
            return 0;
        if(n<0)
            return 10e7;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int a=10e7;
        
        for(int i=n;i>=1;i--)
        {
            if(!perfect(i))
                continue;
            a=min(a,1+solve(n-i,dp));
        }
        
        return dp[n]= a;
    }
    
    int numSquares(int n) {
       
        vector<int> dp(n+1,0);
        
        //return solve(n,dp);
        
        for(int i=1;i<=n;i++)
        {
            int a=10e7;
            if(perfect(i))
            {
                dp[i]=1;
                continue;
            }
            for(int j=1;j*j<=i;j++)
            {
                a=min(a,1+dp[i-j*j]);
            }
            
            dp[i]=a;
        }
        
        
        return dp[n];
    }
};