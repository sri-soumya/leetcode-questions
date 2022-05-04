class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
     
        int n=a.length(),m=b.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int i=n,j=m;
        string c="";
        while(i>0&&j>0)
        {
            if(dp[i][j]!=dp[i-1][j]&&dp[i][j]!=dp[i][j-1])
            {
                c=b[j-1]+c;
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    c=a[i-1]+c;
                    i--;
                }
                else
                {
                    c=b[j-1]+c;
                    j--;
                }
            }
        }
        
        while(i)
        {
            c=a[i-1]+c;
            i--;
        }
        while(j)
        {
            c=b[j-1]+c;
            j--;
        }
        
        return c;
        
    }
};