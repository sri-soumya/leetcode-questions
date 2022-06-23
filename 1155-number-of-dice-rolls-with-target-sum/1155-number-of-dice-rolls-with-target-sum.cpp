#define mod 1000000007
class Solution {
public:
    
    int solve(int n,int k,int t,vector<vector<int>> &dp)
    {
        if(n<=0||k<=0||t<=0)
            return 0;
        
        if(n==1&&t<=k)
            return 1;
        
        if(dp[n][t]!=-1)
            return dp[n][t];
        
        int a=0;
        
        for(int i=1;i<=k;i++)
        {
            int x=solve(n-1,k,t-i,dp)%mod;
            a=(a+x)%mod;
        }
        
        return dp[n][t]= a%mod;
        
    }
    
    int numRollsToTarget(int n, int k, int t) {
        
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));
        
        //return solve(n,k,t,dp);
        
        for(int i=1;i<=t;i++)
        {
            dp[1][i]=i<=k;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=t;j++)
            {
                int a=0;
                for(int z=1;z<=k;z++)
                {
                    if(j-z<0)
                        continue;
                    int x=dp[i-1][j-z]%mod;
                    a=(a+x)%mod;
                }
                dp[i][j]=a%mod;
            }
        }
        
        return dp[n][t];
        
    }
};