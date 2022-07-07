class Solution {
public:
    
    bool solve(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>> &dp)
    {
        if(i==0&&j==0&&k==0)
            return true;
        
        if(k==0&&(i||j))
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool f1=0,f2=0;
        if(i>0&&s1[i-1]==s3[k-1])
            f1=solve(s1,s2,s3,i-1,j,k-1,dp);
        if(j>0&&s2[j-1]==s3[k-1])
            f2=solve(s1,s2,s3,i,j-1,k-1,dp);
        
        return dp[i][j]=f1||f2;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.length(),m=s2.length(),k=s3.length();
        
        if(n+m!=k)
            return false;
        
        //vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return solve(s1,s2,s3,n,m,k,dp);
        vector<int> dp(m+1,0);
        dp[0]=1;
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0&&j==0)
                    continue;
                int k=i+j;
                bool f1=0,f2=0;
                if(i>0&&s1[i-1]==s3[k-1])
                    f1=dp[j];
                if(j>0&&s2[j-1]==s3[k-1])
                    f2=dp[j-1];
                
                dp[j]=f1||f2;
                
            }
        }
        
        return dp[m];
     }
};