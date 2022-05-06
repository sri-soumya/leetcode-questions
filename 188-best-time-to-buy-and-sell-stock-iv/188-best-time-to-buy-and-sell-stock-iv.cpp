class Solution {
public:
    int maxProfit(int m, vector<int>& a) {
        
        int n=a.size();
        //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(m+1,0)));
        //return solve(a,0,1,2,dp);
        
        vector<vector<int>> ahead(2,vector<int>(m+1,0)),cur(2,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int f=0;f<2;f++)
            {
                for(int k=1;k<=m;k++)
                {
                    if(f)
                    {
                        cur[f][k]=max(-a[i]+ahead[0][k],ahead[1][k]);
                    }
                    else
                    {
                        cur[f][k]=max(a[i]+ahead[1][k-1],ahead[0][k]);
                    }
                }
            }
            
            ahead=cur;
        }
        
        return ahead[1][m];
        
    }
};