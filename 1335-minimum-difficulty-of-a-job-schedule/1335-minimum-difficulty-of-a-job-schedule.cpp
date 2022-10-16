class Solution {
public:
    
    int solve(vector<int>& a, int d, int i, vector<vector<int>> &dp)
    {
        int n=a.size();
        
        if(d<0)
            return -1;
        
        if(i>=n)
        {
            if(!d)
                return 0;
            return -1;
        }
        
        if(dp[i][d]!=INT_MIN)
            return dp[i][d];
        
        int m=INT_MIN,ans=1e8;
        
        for(int j=i;j<n;j++)
        {
            m=max(m,a[j]);
            int x=solve(a,d-1,j+1,dp);
            if(x!=-1)
                ans=min(ans,m+x);
        }
        
        if(ans>=1e8)
            ans=-1;
        
        return dp[i][d]= ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>> dp(n,vector<int>(d+1,INT_MIN));
        
        return solve(jobDifficulty,d,0,dp);
    }
};