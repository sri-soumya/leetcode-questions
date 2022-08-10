class Solution {
public:
    
    double solve(int n,int k,int r,int c,vector<vector<vector<double>>> &dp)
    {
        if(r<0||c<0||r>=n||c>=n)
            return 0;
        if(k==0)
            return 1.0;
        
        if(dp[r][c][k]!=-1)
            return dp[r][c][k];
        
        vector<vector<int>> moves={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
        
        double ans=0;
        
        for(auto x:moves)
        {
            ans+=solve(n,k-1,r+x[0],c+x[1],dp);
        }
        
        return dp[r][c][k]= ans/8.0;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1))); 
        
        return solve(n,k,row,column,dp);
        
    }
};