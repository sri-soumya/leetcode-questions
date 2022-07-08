class Solution {
public:
    
    int solve(vector<int>& a, vector<vector<int>>& b, int i, int p, int t,vector<vector<vector<int>>> &dp)
    {
       int n=a.size(),m=b[0].size();
        
        if(t<0)
            return 1e8;
        
        if(i==n)
        {
            if(!t)
                return 0;
            return 1e8;
        }
        
        if(dp[i][p][t]!=-1)
            return  dp[i][p][t];
        
        int tt=t;
        if(a[i]!=p)
            tt--;
        
        if(a[i]!=0)
            return dp[i][p][t]= solve(a,b,i+1,a[i],tt,dp)+0;
        
        int ans=INT_MAX;
        
        for(int j=1;j<=m;j++)
        {
            tt=t;
            if(j!=p)
                tt--;
            int x=solve(a,b,i+1,j,tt,dp);
            if(x!=1e8)
                ans=min(ans,x+b[i][j-1]);
        }
        
        if(ans==INT_MAX)
            return dp[i][p][t]= 1e8;
        return dp[i][p][t]= ans;
        
    }
    
    int minCost(vector<int>& a, vector<vector<int>>& b, int m, int n, int t) {
     
       // int n=a.size(),m=b[0].size();
        
        //vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+1,vector<int>(t+1,-1)));
        int x= solve(a,b,0,0,t,dp);
        if(x==1e8)
            return -1;
        return x;
        
    }
};