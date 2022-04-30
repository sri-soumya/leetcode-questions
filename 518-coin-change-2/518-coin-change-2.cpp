class Solution {
public:
    
    int solve(vector<int> a,int i,int t,vector<vector<int>> &dp)
    {
        if(!t)
            return 1;
        if(t<0)
            return 0;
        if(!i)
        {
            return !(t%a[0]);
        }
        
        if(dp[i][t]!=-1)
            return dp[i][t];
        
        return dp[i][t]= solve(a,i-1,t,dp)+solve(a,i,t-a[i],dp);
    }
    
    int change(int t, vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(t+1,0));
        //return solve(c,n-1,a,dp);
        
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=t;i++)
            if(i%a[0]==0)
                dp[0][i]=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=t;j++)
            {
                int c1=dp[i-1][j],c2=0;
                if(j>=a[i])
                    c2=dp[i][j-a[i]];
                dp[i][j]=c1+c2;
            }
        }
        
        return dp[n-1][t];
    }
};