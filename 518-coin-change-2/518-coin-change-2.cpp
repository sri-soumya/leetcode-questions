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
    
    int change(int a, vector<int>& c) {
        int n=c.size();
        vector<vector<int>> dp(n,vector<int>(a+1,-1));
        return solve(c,n-1,a,dp);
    }
};