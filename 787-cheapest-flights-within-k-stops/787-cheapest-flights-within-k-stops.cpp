#define ff first
#define ss second
class Solution {
public:
    
    int solve(vector<vector<pair<int,int>>> &e,int i,int t,int k,vector<vector<int>> &dp)
    {
        if(k<0)
            return 1e7;
        if(i==t)
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int d=1e7;
        
        for(auto x:e[i])
        {
            d=min(d,x.ss+solve(e,x.ff,t,k-1,dp));
        }
        
        return dp[i][k]= d;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> e(n);
        
        for(int i=0;i<flights.size();i++)
        {
            e[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        k++;
        
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
        int x=solve(e,src,dst,k,dp);
        
        if(x>=1e7)
            return -1;
        return x;
    }
};