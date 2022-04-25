class Solution {
public:
    
    int solve(vector<vector<int>>& a,int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>m||j>n||a[i][j]==1)
            return 0;
        if(i==m&&j==n)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=solve(a,i+1,j,m,n,dp)+solve(a,i,j+1,m,n,dp);
    }

    
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(a,0,0,m-1,n-1,dp);
    }
};