class Solution {
public:
    
    double solve(int p,int r,int c,vector<vector<double>> &dp)
    {
        
        if(r<0||c<0||c>r)
            return 0;
        if(r==0&&c==0)
            return p;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        double le=max(0.0,(solve(p,r-1,c-1,dp)-1)/2.0);
        double ri=max(0.0,(solve(p,r-1,c,dp)-1)/2.0);
        
        return dp[r][c]= le+ri;
        
    }
    
    double champagneTower(int p, int r, int c) {
        
        // if(r==0&&c==0)
        //     return min(p,1);
        vector<vector<double>> dp(r+1,vector<double>(c+1,0));
        //return min(1.0,solve(p,r,c,dp));
        
        dp[0][0]=p;
        
        for(int i=1;i<=r;i++)
        {
            for(int j=0;j<=c;j++)
            {
                double le=0.0,ri=0.0;
                if(j-1>=0&&j-1<=i-1)
                    le=dp[i-1][j-1];
                if(j<=i-1)
                    ri=dp[i-1][j];
                le=max(0.0,(le-1)/2.0);
                ri=max(0.0,(ri-1)/2.0);
                
                dp[i][j]=le+ri;
            }
        }
        
        return min(1.0,dp[r][c]);
        
    }
};