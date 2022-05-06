class Solution {
public:
    
    bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        int n=s.length(),m=p.length();
        
        if(i==0&&j>0)
        {
            for(;j>=1;j--)
            {
                if(p[j-1]!='*')
                    return false;
            }
            return true;
        }
        
        if(i==0&&j==0)
            return true;
        if(j==0)
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i-1]==p[j-1])
            return dp[i][j]= solve(s,p,i-1,j-1,dp);
        if(p[j-1]=='?')
            return dp[i][j]= solve(s,p,i-1,j-1,dp);
        if(p[j-1]=='*')
        {
            return dp[i][j]=solve(s,p,i,j-1,dp)||solve(s,p,i-1,j,dp);
        }
        return dp[i][j]= false;
    }
    
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return solve(s,p,n,m,dp);
        
        dp[0][0]=1;
        
        for(int i=1;i<=m;i++)
        {
            bool f=true;
            for(int j=i;j>=1;j--)
            {
                if(p[j-1]!='*')
                {
                    f=false;
                    break;
                }
            }
            dp[0][i]=f;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else
                    dp[i][j]=false;
            }
        }
        
        return dp[n][m];
    }
};