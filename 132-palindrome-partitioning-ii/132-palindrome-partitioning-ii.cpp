class Solution {
public:
    
    bool ispal(string &s,int i,int j)
    {
        if(i>=j)
            return true;
        return s[i]==s[j]&&ispal(s,i+1,j-1);
    }
    
    int solve(string &s,int i,int j,vector<int> &dp)
    {
        
        if(i>j)
            return -1;
        
        if(i==j)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            if(ispal(s,i,k))
            {
                int x=solve(s,k+1,j,dp)+1;
                ans=min(ans,x);
                //cout<<i<<" "<<j<<ans<<endl;
            }
        }

        return dp[i]= ans;
    }
    
    int minCut(string s) {
        
        int n=s.length();
        vector<int> dp(n,-1);        
        int a= solve(s,0,n-1,dp);
        return a;
        
        
    }
};