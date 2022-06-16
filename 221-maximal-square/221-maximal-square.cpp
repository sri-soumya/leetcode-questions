class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        
        int n=a.size(),m=a[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        int x=0;
        for(int i=0;i<m;i++)
        {
            dp[0][i]=a[0][i]=='1';
            x=max(x,dp[0][i]);
        }
        
        for(int i=1;i<n;i++)
        {
            dp[i][0]=a[i][0]=='1';
            x=max(x,dp[i][0]);
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(a[i][j]=='0')
                    continue;
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                x=max(x,dp[i][j]);
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        return x*x;
        
    }
};