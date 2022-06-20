class Solution {
public:
    
    int solve(vector<int> a,int i,int in,int k,vector<vector<vector<int>>> &dp)
    {
        if(i==0)
            return 0;
        
        if(dp[i][in][k]!=-1)
            return dp[i][in][k];
        
        if(in==0)
        {
            return dp[i][in][k]= max(solve(a,i-1,i,k,dp)+1,solve(a,i-1,in,k,dp));
        }
        
        int x=a[in-1]-a[i-1];
        if(x<0)
            x=1;
        else if(x>0)
            x=2;
        
        if(x==0)
            return dp[i][in][k]= solve(a,i-1,in,k,dp);
        
        if(k==0)
        {
            int op1=solve(a,i-1,in,k,dp);
            
            if(x==1)
               op1=max(op1,solve(a,i-1,i,2,dp)+1);
            else
                op1=max(op1,solve(a,i-1,i,1,dp)+1);
            
            return dp[i][in][k]= op1;
        }
        
        if(x!=k)
            return dp[i][in][k]= solve(a,i-1,in,k,dp);
        
        if(x==1)
            return dp[i][in][k]= max(solve(a,i-1,in,k,dp),solve(a,i-1,i,2,dp)+1);
        return dp[i][in][k]= max(solve(a,i-1,in,k,dp),solve(a,i-1,i,1,dp)+1);
    }

    
    int wiggleMaxLength(vector<int>& a) {
        int n=a.size();
        
        //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(3,-1)));
        
        //return solve(a,n,0,0,dp);
        
        vector<pair<int,int>> dp(n,{1,1});
        
        int ans=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(a[i]>a[j])
                    dp[i].first=max(dp[i].first,dp[j].second+1);
                 if(a[i]<a[j])
                    dp[i].second=max(dp[i].second,dp[j].first+1);
            }
            
            ans=max(ans,max(dp[i].first,dp[i].second));
        }
        
        return ans;
        
    }
};