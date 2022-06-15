class Solution {
public:
    
    bool solve(vector<int> &a,int i,vector<int> &dp)
    {
        int n=a.size();
        
        if(i==n-1)
            return true;
        
        if(dp[i]!=-1)
            return dp[i];
        
        for(int j=1;j<=a[i];j++)
        {
            if(i+j>=n)
                break;
            //bool f=solve(a,i+j);
            if(solve(a,i+j,dp))
                return dp[i]= true;
        }
        
        return dp[i]= false;
    }
    
    bool canJump(vector<int>& a) {
        int n=a.size();
        
        vector<int> dp(n,-1);
        
        return solve(a,0,dp);
        
    }
};