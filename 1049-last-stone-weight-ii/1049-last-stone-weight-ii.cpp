class Solution {
public:
    
    int lastStoneWeightII(vector<int>& a) {
        
        int n=a.size(),s=0;
        
        for(auto x:a)
            s+=x;
        
        vector<vector<int>> dp(n+1,vector<int>(s/2+1,0));
        
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s/2;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-a[i-1]>=0)
                    dp[i][j]=dp[i][j]||dp[i-1][j-a[i-1]];
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<=s/2;i++)
        {
            if(dp[n][i]==0)
                continue;
            ans=min(ans,s-2*i);
        }
        
        return ans;
    }
};