class Solution {
public:
    
    int solve(vector<vector<int>> a,int i,int j,vector<vector<int>> &dp)
    {
        int n=a.size();
        if(i>=n)
            return INT_MAX;
        int m=a[i].size();
        if(j>=m)
            return INT_MAX;
        if(i==n-1)
            return a[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=a[i][j]+min(solve(a,i+1,j,dp),solve(a,i+1,j+1,dp));
    }
    
    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        vector<vector<int>> dp;
        for(int i=0;i<n;i++)
        {
            vector<int> b(a[i].size(),-1);
            dp.push_back(b);
        }
        //return solve(a,0,0,dp);
        
        dp[n-1]=a[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<a[i].size();j++)
            {
                int c1=dp[i+1][j],c2=INT_MAX;
                if(j+1<dp[i+1].size())
                    c2=dp[i+1][j+1];
                dp[i][j]=a[i][j]+min(c1,c2);
            }
        }
        
        return dp[0][0];
        
    }
};