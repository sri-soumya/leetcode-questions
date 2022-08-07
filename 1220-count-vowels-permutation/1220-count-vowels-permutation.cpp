#define mod 1000000007
#define ll long long int
class Solution {
public:
    
    ll solve(int n,int c,vector<vector<ll>> &dp)
    {
        if(n<=0)
            return 1;
        
        if(dp[n][c]!=-1)
            return dp[n][c];
        
        if(c==0)
        {
            return dp[n][c]= (solve(n-1,'a',dp)%mod+solve(n-1,'e',dp)%mod+solve(n-1,'i',dp)%mod+solve(n-1,'o',dp)%mod+solve(n-1,'u',dp)%mod)%mod;
        }
        
        else if(c=='a')
        {
            return dp[n][c]= solve(n-1,'e',dp)%mod;
        }
        else if(c=='e')
        {
            return dp[n][c]= (solve(n-1,'a',dp)%mod+solve(n-1,'i',dp)%mod)%mod;
        }
        else if(c=='i')
        {
            return dp[n][c]= (solve(n-1,'a',dp)%mod+solve(n-1,'e',dp)%mod+solve(n-1,'o',dp)%mod+solve(n-1,'u',dp)%mod)%mod;
        }
        
        else if(c=='o')
        {
            return dp[n][c]= (solve(n-1,'i',dp)%mod+solve(n-1,'u',dp)%mod)%mod;
        }
        
        return dp[n][c]= solve(n-1,'a',dp)%mod;
    }
    
    int countVowelPermutation(int n) {
        
        vector<vector<ll>> dp(n+1,vector<ll>(122,-1));
        return solve(n,0,dp)%mod;
        
    }
};