class Solution {
public:
    
    int solve(vector<int> &a,int i,int k,vector<int> &dp)
    {
        int n=a.size();
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int m=a[i],ans=INT_MIN;
        for(int j=1;j<=k&&i+j<=n;j++)
        {
            int x=m*j+solve(a,i+j,k,dp);
            ans=max(ans,x);
            if(i+j<n)
                m=max(m,a[i+j]);
        }
        
        return dp[i]= ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        
        int n=a.size();
        vector<int> dp(n+1,0);
        //return solve(a,0,k,dp);
        
        for(int i=n-1;i>=0;i--)
        {
            int m=a[i],ans=INT_MIN;
            for(int j=1;j<=k&&i+j<=n;j++)
            {
                int x=m*j+dp[i+j];
                ans=max(ans,x);
                if(i+j<n)
                    m=max(m,a[i+j]);
            }
            
            dp[i]=ans;
        }
        
        return dp[0];
    }
};