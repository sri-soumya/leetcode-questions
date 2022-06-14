class Solution {
public:
    
    int solve(string &a,string &b,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0||j<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==b[j])
            return dp[i][j]= 1+solve(a,b,i-1,j-1,dp);
        return dp[i][j]= max(solve(a,b,i-1,j,dp),solve(a,b,i,j-1,dp));
    }
    
    int minDistance(string a, string b) {
        int n=a.length(),m=b.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return m+n-2*solve(a,b,n-1,m-1,dp);
    }
};