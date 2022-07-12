class Solution {
public:
    
    int solve(vector<int> &a,vector<int> &b,int i,vector<int> &dp)
    {
        int n=a.size();
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int c1=solve(a,b,i+1,dp)+b[0];
        
        int j=i+1;
        for(;j<n;j++)
        {
            if(a[j]-a[i]>=7)
                break;
        }
        
        int c2=solve(a,b,j,dp)+b[1];
        
        j=i+1;
        for(;j<n;j++)
        {
            if(a[j]-a[i]>=30)
                break;
        }
        
        int c3=solve(a,b,j,dp)+b[2];
        
        return dp[i]= min(c1,min(c2,c3));
    }
    
    
    int mincostTickets(vector<int>& a, vector<int>& b) {
        
        int n=a.size();
        vector<int> dp(n,-1);
        return solve(a,b,0,dp);
        
        
    }
};