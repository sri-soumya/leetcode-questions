class Solution {
public:
    
    int solve(vector<int> a,int i,int f,vector<vector<int>> &dp)
    {
        int n=a.size();
        if(i==n)
            return 0;
        int m=0;
        if(dp[i][f]!=-1)
            return dp[i][f];
        if(f)
        {
            m=max(-a[i]+solve(a,i+1,0,dp),solve(a,i+1,1,dp));
        }
        
        else
        {
            m=max(a[i]+solve(a,i+1,1,dp),solve(a,i+1,0,dp));
        }
        
        return dp[i][f]= m;
    }
    
    int maxProfit(vector<int>& a) {
        
        int n=a.size();
        //vector<vector<int>> dp(n+1,vector<int>(2,0));
        //return solve(a,0,1,dp);
        vector<int> ahead(2,0),cur(2,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j)
                    cur[j]=max(-a[i]+ahead[0],ahead[1]);
                else
                    cur[j]=max(a[i]+ahead[1],ahead[0]);
            }
            
            ahead=cur;
        }
        
        return cur[1];
        
    }
};