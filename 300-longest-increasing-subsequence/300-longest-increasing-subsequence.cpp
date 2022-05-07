class Solution {
public:
    
    int solve(vector<int> &a,int i,vector<int> &dp)
    {
        if(i==0)
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int c=0;
    
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
                c=max(c,solve(a,j,dp));
        }
        
        return dp[i]= c+1;
    }
    
    int lengthOfLIS(vector<int>& a) {
        int c=0,n=a.size();
        vector<int> dp(n+1,-1);
        for(int i=n-1;i>=0;i--)
            c=max(c,solve(a,i,dp));
        return c;
    }
};