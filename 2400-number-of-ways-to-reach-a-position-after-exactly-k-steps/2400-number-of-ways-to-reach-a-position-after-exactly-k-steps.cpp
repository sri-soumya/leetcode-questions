#define mod 1000000007
class Solution {
public:
    
    int solve(int i,int j,int k,vector<vector<int>> &dp)
    {
        if(!k&&i==j)
            return 1;
        if(!k)
            return 0;
        
        if(dp[i+1000][k]!=-1)
            return dp[i+1000][k];
        
        return dp[i+1000][k]= (solve(i-1,j,k-1,dp)%mod+solve(i+1,j,k-1,dp)%mod)%mod;
    }
    
    int numberOfWays(int i, int j, int k) {
        
        //unordered_map<int,unordered_map<int,int>> dp;
        vector<vector<int>> dp(5000,vector<int>(k+1,-1));
        return solve(i,j,k,dp)%mod;
        
    }
};