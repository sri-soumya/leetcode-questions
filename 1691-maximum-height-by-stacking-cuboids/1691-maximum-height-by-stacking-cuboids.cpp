class Solution {
public:
    int maxHeight(vector<vector<int>>& a) {
        
        int n=a.size();
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++)
            sort(a[i].begin(),a[i].end());
        
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=a[i][2];
            
            for(int j=i-1;j>=0;j--)
            {
                if(a[i][0]>=a[j][0]&&a[i][1]>=a[j][1]&&a[i][2]>=a[j][2])
                    dp[i]=max(dp[i],a[i][2]+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};