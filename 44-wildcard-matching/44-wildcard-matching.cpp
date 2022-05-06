class Solution {
public:
    
    bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        int n=s.length(),m=p.length();
        
        if(i==n&&j!=m)
        {
            for(;j<m;j++)
            {
                if(p[j]!='*')
                    return false;
            }
            return true;
        }
        
        if(i==n&&j==m)
            return true;
        if(i==n||j==m)
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==p[j])
            return dp[i][j]= solve(s,p,i+1,j+1,dp);
        if(p[j]=='?')
            return dp[i][j]= solve(s,p,i+1,j+1,dp);
        if(p[j]=='*')
        {
            return dp[i][j]=solve(s,p,i,j+1,dp)||solve(s,p,i+1,j,dp);
        }
        return dp[i][j]= false;
    }
    
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0,dp);
    }
};