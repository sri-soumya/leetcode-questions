class Solution {
public:
    
    int solve(vector<vector<int>> a,int i,int j1,int j2,vector<vector<vector<int>>> &dp)
    {
        int m=a.size(),n=a[0].size();
        if(j1<0||j2<0||j1>=n||j2>=n)
            return INT_MIN;
        if(i==m-1)
        {
            if(j1==j2)
                return a[i][j1];
            return a[i][j1]+a[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        
        int ma=INT_MIN;
        for(int x=-1;x<=1;x++)
        {
            for(int y=-1;y<=1;y++)
                ma=max(ma,solve(a,i+1,j1+x,j2+y,dp));
        }
        
        if(j1!=j2)
            return dp[i][j1][j2]=ma+a[i][j1]+a[i][j2];
        return dp[i][j1][j2]= ma+a[i][j1];
    }
    
    int cherryPickup(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        //return solve(a,0,0,a[0].size()-1,dp);
        
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                    dp[n-1][j1][j2]=a[n-1][j1];
                else
                   dp[n-1][j1][j2]=a[n-1][j1]+a[n-1][j2]; 
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int ma=INT_MIN;
                    for(int x=-1;x<=1;x++)
                    {
                        for(int y=-1;y<=1;y++)
                        {
                            if(j1+x<0||j1+x>=m||j2+y<0||j2+y>=m)
                                continue;
                            ma=max(ma,dp[i+1][j1+x][j2+y]);
                        }
                    }
                    
                    if(j1==j2)
                        dp[i][j1][j2]=a[i][j1]+ma;
                    else
                        dp[i][j1][j2]=a[i][j1]+a[i][j2]+ma;
                }
            }
            
        }
        
        return dp[0][0][m-1];
        
    }
};