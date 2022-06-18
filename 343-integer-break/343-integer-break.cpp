class Solution {
public:
    
    int solve(int n,vector<int> &dp)
    {
        if(n<=1)
            return n;
        // if(n<=3)
        //     return n-1;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int a=0;
        
        for(int i=1;i<n;i++)
        {
            a=max(a,i*solve(n-i,dp));
            //cout<<i<<" "<<a<<endl;
        }
        
        return dp[n]= max(a,n);
    }
    
    int integerBreak(int n) {
     
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        
        vector<int> dp(n+1,-1);
        
        return solve(n,dp);
        
    }
};