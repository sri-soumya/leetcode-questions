class Solution {
public:
    //k=0-any,=1-should be +ve,=2-should be -ve
    int solve(vector<int> &a,int i,int j,int k,vector<vector<vector<int>>> &dp)
    {
        
        if(i<=0)
            return 0;
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        int c1=solve(a,i-1,j,k,dp),c2=-1e7;
        
        if(!j)
            c2=solve(a,i-1,i,k,dp)+1;
        
        else
        {
            int z=a[j-1]-a[i-1];
            if(!k)
            {
                if(z<0)
                    c2=solve(a,i-1,i,1,dp)+1;
                else if(z>0)
                    c2=solve(a,i-1,i,2,dp)+1;
            }
            
            else if(k==1&&z>0)
                c2=solve(a,i-1,i,2,dp)+1;
            else if(k==2&&z<0)
                c2=solve(a,i-1,i,1,dp)+1;
            
        }
        
        return dp[i][j][k]= max(c1,c2);
        
    }
    
    int wiggleMaxLength(vector<int>& a) {
        
        int n=a.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(3,-1)));
        
        return solve(a,n,0,0,dp);
        
    }
};