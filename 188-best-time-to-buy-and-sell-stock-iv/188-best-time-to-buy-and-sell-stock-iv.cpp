class Solution {
public:
    
    int solve(vector<int> &prices,int i,int k,int f,vector<vector<vector<int>>> &dp)
    {
        int n=prices.size();
        
        if(k<0)
            return -1e7;
        
        if(i==n)
            return 0;
        
        if(dp[i][k][f]!=-1)
            return dp[i][k][f];
        
        int c1=solve(prices,i+1,k,f,dp);
        int c2=0;
        
        if(f)
            c2=solve(prices,i+1,k-1,0,dp)+prices[i];
        else
            c2=solve(prices,i+1,k,1,dp)-prices[i];
        
        return dp[i][k][f]= max(c1,c2);
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        //return solve(prices,0,k,0,dp);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=k;j++)
            {
                for(int z=0;z<2;z++)
                {
                    int c1=dp[i+1][j][z];
                    int c2;
                    if(j-1<0)
                        c2=-1e7;
                    else if(z)
                        c2=dp[i+1][j-1][0]+prices[i];
                    else
                        c2=dp[i+1][j][1]-prices[i];
                    dp[i][j][z]=max(c1,c2);
                }
            }
        }
        
        return dp[0][k][0];
    }
};