class Solution {
public:
    
    /*1-up
    2-down
    3-left
    4-right*/
    
    
    int solve(vector<vector<int>>& a,int i,int j,int p,vector<vector<vector<int>>> &dp)
    {
        int n=a.size(),m=a[0].size();
        if(i<0||j<0||i>=n||j>=m)
            return 0;
        //cout<<i<<" "<<j<<endl;
        
        if(dp[i][j][p]!=-1)
            return dp[i][j][p];
        
        int x=INT_MIN;
        if(p==1)
            x=a[i-1][j];
        else if(p==2)
            x=a[i+1][j];
        else if(p==3)
            x=a[i][j-1];
        else if(p==4)
            x=a[i][j+1];
        
        if(x>=a[i][j])
            return dp[i][j][p]= 0;
        if(p==1)
            return dp[i][j][p]= 1+max(solve(a,i,j+1,3,dp),max(solve(a,i,j-1,4,dp),solve(a,i+1,j,1,dp)));
        else if(p==2)
            return dp[i][j][p]= 1+max(solve(a,i,j+1,3,dp),max(solve(a,i,j-1,4,dp),solve(a,i-1,j,2,dp)));
        else if(p==3)
            return dp[i][j][p]= 1+max(solve(a,i,j+1,3,dp),max(solve(a,i-1,j,2,dp),solve(a,i+1,j,1,dp)));
        else if(p==4)
            return dp[i][j][p]= 1+max(solve(a,i-1,j,2,dp),max(solve(a,i,j-1,4,dp),solve(a,i+1,j,1,dp)));
        else 
        {
            
            int op1=1+max(max(solve(a,i,j+1,3,dp),solve(a,i,j-1,4,dp)),max(solve(a,i+1,j,1,dp),solve(a,i-1,j,2,dp)));
            int op2=0;
            //op2=max(max(solve(a,i,j+1,0),solve(a,i,j-1,0)),max(solve(a,i+1,j,0),solve(a,i-1,j,0)));
            return dp[i][j][p]= max(op1,op2);
        }
            
            
    }
    
    int longestIncreasingPath(vector<vector<int>>& a) {
     
        int n=a.size(),m=a[0].size();
        //return solve(a,0,0,0);
        int c=0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(5,-1)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                c=max(c,solve(a,i,j,0,dp));
        }
        
        return c;
        
    }
};