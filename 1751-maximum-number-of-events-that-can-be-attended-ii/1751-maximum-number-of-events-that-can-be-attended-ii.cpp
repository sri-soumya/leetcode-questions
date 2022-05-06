class Solution {
public:
    
    static bool compare(vector<int> a,vector<int> b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int solve(vector<vector<int>>& a,int i,int k,vector<vector<int>> &dp)
    {
        if(!k||i<0)
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int c1=INT_MIN,c2=0;
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(a[j][0]>a[i][1])
                break;
        }
        c1=a[i][2]+solve(a,j,k-1,dp);
        c2=solve(a,i-1,k,dp);
        return dp[i][k]= max(c1,c2);
    }
    
    int maxValue(vector<vector<int>>& a, int k) {
        int n=a.size();
        
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(a,n-1,k,dp);
    }
};