class Solution {
public:
    
    int solve(string a,string b,int i,int j,vector<vector<int>> &dp)
    {
        if(i==0||j==0)
        {
            if(!i)
            {
                while(j>=0)
                {
                    if(a[i]==b[j])
                        return 1;
                    j--;
                }
                
                return 0;
            }
            
            if(!j)
            {
                while(i>=0)
                {
                    if(a[i]==b[j])
                        return 1;
                    i--;
                    
                }
                
                return 0;
            }
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==b[j])
            return dp[i][j]=1+solve(a,b,i-1,j-1,dp);
        return dp[i][j]= max(solve(a,b,i-1,j,dp),solve(a,b,i,j-1,dp));
    }
    
    int longestCommonSubsequence(string a, string b) {
        int n=a.length(),m=b.length();
        vector<vector<int>> dp(n,vector<int>(m,0));
        //return solve(a,b,n-1,m-1,dp);
        
        if(a[0]==b[0])
            dp[0][0]=1;
        
        for(int i=1;i<m;i++)
        {
            if(a[0]==b[i])
                dp[0][i]=1;
            else
                dp[0][i]=dp[0][i-1];
        }
        
        for(int i=1;i<n;i++)
        {
            if(a[i]==b[0])
                dp[i][0]=1;
            else
                dp[i][0]=dp[i-1][0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(a[i]==b[j])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n-1][m-1];
    }
};