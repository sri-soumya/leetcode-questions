class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n=questions.size();
        long long dp[n];
        //cout<<n<<endl;
        dp[n-1]=questions[n-1][0];
        long long ans=dp[n-1];
        for(int i=n-2;i>=0;i--)
        {
            long long x=i+questions[i][1]+1;
            long long c1=questions[i][0];
            long long c2=dp[i+1];
            long long c3=(x<n)?c1+dp[x]:c1;
            
            //cout<<i<<" "<<x<<" "<<c1<<" "<<c2<<" "<<c3<<" "<<endl;
            
            dp[i]=max(c1,max(c2,c3));
            ans=max(ans,dp[i]);
        }
        // cout<<endl<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        
        return ans;
        
    }
};