class Solution {
public:
    
    int solve(vector<vector<int>> &a,int i,int j,vector<vector<int>> &dp)
    {
        int n=a.size(),m=a[0].size();
        
        
        if(i>=n||j>=m)
            return 1e7;
        
        if(i==n-1&&j==m-1)
            return a[i][j]>=0?1:-a[i][j]+1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int c1=solve(a,i+1,j,dp),c2=solve(a,i,j+1,dp);
        
        c1=min(c1,c2)-a[i][j];
        return dp[i][j]= c1<=0?1:c1;
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& a) {
        
        int n=a.size(),m=a[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return solve(a,0,0,dp);
        
    }
};