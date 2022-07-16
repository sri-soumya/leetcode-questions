#define mod 1000000007
#define ll long long int
class Solution {
public:
    
    ll solve(int i,int j,int t,int m,int n,vector<vector<vector<ll>>> &dp)
    {
        if(t<0)
            return 0;
        
        if(i<0||j<0||i>=m||j>=n)
            return 1;
        
        if(dp[i][j][t]!=-1)
            return dp[i][j][t];
        
        ll a=solve(i+1,j,t-1,m,n,dp)%mod;
        ll b=solve(i-1,j,t-1,m,n,dp)%mod;
        ll c=solve(i,j+1,t-1,m,n,dp)%mod;
        ll d=solve(i,j-1,t-1,m,n,dp)%mod;
        
        return dp[i][j][t]= (a+b+c+d)%mod;
        
    }
    
    int findPaths(int m, int n, int ma, int r, int c) {
        
        //vector<vector<vector<ll>>> dp(m,vector<vector<ll>>(n,vector<ll>(t+1,0)));
        //vector<vector<vector<ll>>> dp(ma+1,vector<vector<ll>>(m,vector<ll>(n,0)));
        vector<vector<ll>> dp(m,vector<ll>(n,0));
        vector<vector<int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        //return solve(i,j,t,m,n,dp)%mod;
        
        for(int t=1;t<=ma;t++)
        {
            vector<vector<ll>> temp(m,vector<ll>(n,0));
            
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(auto d:dir)
                    {
                        int ni=i+d[0];
                        int nj=j+d[1];
                        
                        if(ni<0||nj<0||ni>=m||nj>=n)
                            temp[i][j]+=1%mod;
                        else
                            temp[i][j]+=((t>0)?dp[ni][nj]:0)%mod;
                    }
                }
            }
            
            dp=temp;

        }
        
        return dp[r][c]%mod;
    }
};