class Solution {
public:
    
    int wiggleMaxLength(vector<int>& a) {
        int n=a.size();
        vector<pair<int,int>> dp(n,{1,1});
        for(int i=1;i<n;i++)
        {
            
            if(a[i]>a[i-1])
            {
                dp[i].first=dp[i-1].second+1;
                dp[i].second=dp[i-1].second;
            }
            
            else if(a[i]<a[i-1])
            {
                dp[i].first=dp[i-1].first;
                dp[i].second=dp[i-1].first+1;
                
            }
            
            else
                dp[i]=dp[i-1];
            
        }
        
        return max(dp[n-1].first,dp[n-1].second);
        
    }
};