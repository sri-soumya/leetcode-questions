class Solution {
public:
    
    int solve(vector<vector<int>> &a,int i,int p,vector<vector<int>> &dp)
    {
        int n=a.size();
        if(i>=n)
            return 0;
        
        if(dp[i][p]!=-1)
            return dp[i][p];
        
        int c1=solve(a,i+1,p,dp);
        int c2=0;
        
        if(a[i][0]>a[p][0]&&a[i][1]>a[p][1])
            c2=solve(a,i+1,i,dp)+1;
        
        return dp[i][p]= max(c1,c2);
    }
    
    static bool compare(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]>b[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& a) {
        
        //a.push_back({0,0});
        sort(a.begin(),a.end(),compare);
        int n=a.size();
        //vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> lis;
        //return solve(a,1,0,dp);
        
        for(int i=0;i<n;i++)
        {
            int in=lower_bound(lis.begin(),lis.end(),a[i][1])-lis.begin();
            if(in==lis.size())
                lis.push_back(a[i][1]);
            else
                lis[in]=min(lis[in],a[i][1]);
        }
        
        return lis.size();
        
    }
};