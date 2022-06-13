class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        
        int n=a.size(),m=a[0].size(),s=0;
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=a[i][0];
            s+=a[i][0];
        }

        for(int i=1;i<m;i++)
        {
            dp[0][i]=a[0][i];
            s+=a[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(a[i][j]==0)
                    continue;
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                s+=dp[i][j];
            }
        }
        
        return s;
       
    }
};