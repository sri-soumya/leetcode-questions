class Solution {
public:
    
    int count(string s)
    {
        int c=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
                c++;
        }
        
        return c;
    }
    
    int solve(vector<pair<int,int>> &b,int m,int n,int i, vector<vector<vector<int>>> &dp)
    {
        if(i==0)
            return 0;
        // if(m<0||n<0)
        //     return -1e7;
        
        //cout<<i<<" "<<m<<" "<<n<<endl;
        
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        
        int op1=solve(b,m,n,i-1,dp);
        int op2=0;
        if(m-b[i-1].first>=0&&n-b[i-1].second>=0)
            op2=solve(b,m-b[i-1].first,n-b[i-1].second,i-1,dp)+1;
        
        return dp[i][m][n]= max(op1,op2);
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> a;
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<strs.size();i++)
        {
            int x=count(strs[i]);
            a.push_back({x,strs[i].length()-x});
        }
        
        return solve(a,m,n,strs.size(),dp);
        int l=strs.size();
        
        for(int i=1;i<=l;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    int op1=dp[i-1][m][n],op2=0;
                    if(j-a[i-1].first>=0&&k-a[i-1].second>=0)
                        op2=dp[i-1][j-a[i-1].first][k-a[i-1].second]+1;
                    dp[i][j][k]=max(op1,op2);
                }
            }
        }
        
        return dp[l][m][n];
    }
};