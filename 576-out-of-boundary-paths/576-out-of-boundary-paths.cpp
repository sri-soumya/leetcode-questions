#define mod 1000000007
#define ll long long int
class Solution {
public:
    
    ll solve(int i,int j,int t,int m,int n,vector<vector<vector<ll>>> &dp)
    {
        if(t<0)
            return 0;
        
        if(i<0||j<0||i>=m||j>=n)
            return 1;
        
        if(dp[i][j][t]!=-1)
            return dp[i][j][t];
        
        ll a=solve(i+1,j,t-1,m,n,dp)%mod;
        ll b=solve(i-1,j,t-1,m,n,dp)%mod;
        ll c=solve(i,j+1,t-1,m,n,dp)%mod;
        ll d=solve(i,j-1,t-1,m,n,dp)%mod;
        
        return dp[i][j][t]= (a+b+c+d)%mod;
        
    }
    
    int findPaths(int m, int n, int ma, int i, int j) {
        
        vector<vector<vector<ll>>> dp(m,vector<vector<ll>>(n,vector<ll>(ma+1,-1)));
        
        return solve(i,j,ma,m,n,dp)%mod;
        
    }
};