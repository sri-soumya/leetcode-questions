#define ll long long int
#define mod 1000000007
class Solution {
public:
    
    ll solve(int n,bool p,vector<vector<ll>> &dp)
    {
        if(n<0)
            return 0;
        if(n==0)
            return !p;
        
        if(dp[n][p]!=-1)
            return dp[n][p];
        
        if(!p)
        {
            return dp[n][p]= (solve(n-1,false,dp)%mod+solve(n-2,false,dp)%mod+2*solve(n-2,true,dp)%mod)%mod;
        }
        
        return dp[n][p]= (solve(n-1,false,dp)%mod+solve(n-1,true,dp)%mod)%mod;
    }
    
    int numTilings(int n) {
        
        vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
        return solve(n,false,dp);
        
    }
};