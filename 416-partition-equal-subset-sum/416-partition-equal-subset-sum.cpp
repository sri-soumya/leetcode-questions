class Solution {
public:
    bool canPartition(vector<int>& a) {
        
        int s=0,n=a.size();
        for(int i=0;i<n;i++)
            s+=a[i];
        
        if(s%2)
            return false;
        
        int t=s/2;
        
        vector<vector<bool>> dp(n,vector<bool>(s+1,0));
        
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        dp[0][a[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                bool c1=false,c2=false;
                c1=dp[i-1][j];
                if(j>=a[i])
                    c2=dp[i-1][j-a[i]];
                dp[i][j]=c1||c2;
            }
        }
        
        return dp[n-1][t];
        
    }
};