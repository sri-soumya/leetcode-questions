class Solution {
public:
    
    int solve(string s,int i,int j,int** dp)
    {
        int n=s.length();
        
        if(i>=n||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=(s[i]==s[j])?1+solve(s,i+1,j-1,dp):max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    }
    
    int minInsertions(string s) {
        
       int **dp=new int*[s.length()+1];
        for(int i=0;i<=s.length();i++)
        {
            dp[i]=new int[s.length()+1];
            for(int j=0;j<=s.length();j++)
                dp[i][j]=-1;
        }
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i]==s[n-1-j])
                    dp[i+1][j+1]=1+dp[i][j];
                else
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        
        return n-dp[n][n]-1;
        
    }
};