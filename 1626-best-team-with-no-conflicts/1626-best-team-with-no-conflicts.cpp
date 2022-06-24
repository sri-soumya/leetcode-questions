class Solution {
public:
    
    int solve(vector<pair<int,int>> &a,int i,int p,vector<vector<int>> &dp)
    {
        if(i==0)
            return 0;
        
        bool f=true;
        
        if(dp[i][p]!=-1)
            return dp[i][p];
        
        if(p!=0&&a[i-1].first>a[p].first&&a[i-1].second<a[p].second)
            f=false;
        else if(p!=0&&a[p].first>a[i-1].first&&a[p].second<a[i-1].second)
            f=false;
            
        int op1=0,op2=0;
        
        op1=solve(a,i-1,p,dp);
        if(f)
            op2=solve(a,i-1,i-1,dp)+a[i-1].second;
        
        return dp[i][p]= max(op1,op2);
        
    }
    
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        
        int n=s.size();
        
        vector<pair<int,int>> c;
        for(int i=0;i<n;i++)
            c.push_back({a[i],s[i]});
        
        sort(c.begin(),c.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(c,n,0,dp);
        
    }
};