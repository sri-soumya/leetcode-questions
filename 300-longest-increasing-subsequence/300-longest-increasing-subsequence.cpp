class Solution {
public:
    
    int solve(vector<int> &a,int i,int j,vector<vector<int>> &dp)
    {
        int n=a.size();
        if(i==n)
            return 0;
        
        if(j!=-1&&dp[i][j]!=-1)
            return dp[i][j];
        
        int c1=solve(a,i+1,j,dp);
        int c2=0;
        if(j==-1||a[j]<a[i])
            c2=1+solve(a,i+1,i,dp);
        
        if(j!=-1)
            dp[i][j]=max(c1,c2);
        
        return max(c1,c2);
    }
    
    int lengthOfLIS(vector<int>& a) {
        int c=0,n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(a,0,-1,dp);
        
    }
    
    
};