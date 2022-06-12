class Solution {
public:
    
    int solve(vector<int> &a,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(i==j)
            return a[j+1]-a[i-1];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k=i;k<=j;k++)
        {
            int x=solve(a,i,k-1,dp)+solve(a,k+1,j,dp);
            ans=min(ans,x);
        }
        
        return dp[i][j]= ans+a[j+1]-a[i-1];
    }
    
    int minCost(int k, vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        //a.push_front(0);
        a.insert(a.begin(),0);
        a.push_back(k);
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        
        return solve(a,1,n,dp);
        
        
    }
};