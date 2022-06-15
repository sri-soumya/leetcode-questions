class Solution {
public:
    
    int solve(vector<int> &a,int i,int j,vector<vector<int>> &dp)
    {
        if(i<=0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int c1=solve(a,i-1,j,dp),c2=0;
        if(j==0||a[i-1]<a[j-1])
            c2=1+solve(a,i-1,i,dp);
        
        return dp[i][j]= max(c1,c2);
    }
    
    int lengthOfLIS(vector<int>& a) {
        
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(a,n,0,dp);
        
    }
};