class Solution {
public:
    
    int solve(string a,string b,int i,int j,vector<vector<int>> &dp)
    {
        if(j==0&&i==0)
            return 0;
        
        if(j==0)
            return i;
        
        if(i==0)
            return j;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i-1]==b[j-1])
            return dp[i][j]= solve(a,b,i-1,j-1,dp);
        return dp[i][j]= min(solve(a,b,i,j-1,dp),min(solve(a,b,i-1,j,dp),solve(a,b,i-1,j-1,dp)))+1;
    }
    
    int minDistance(string a, string b) {
        int n=a.length(),m=b.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(a,b,n,m,dp);
    }
};