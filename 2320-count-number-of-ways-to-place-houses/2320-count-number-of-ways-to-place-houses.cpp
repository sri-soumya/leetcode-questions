#define mod 1000000007
class Solution {
public:
    
    long long int solve(int n,vector<long long int> &dp)
    {
        if(n<=0)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n]= (solve(n-1,dp)%mod+solve(n-2,dp)%mod)%mod;
    }
        
    
    int countHousePlacements(int n) {
        
        vector<long long int> dp(n+1,-1);
        long long int c=solve(n,dp)%mod;
        return (c*c)%mod;
        
    }
};