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
        if(i<0)
            return 0;
        // if(m<0||n<0)
        //     return -1e7;
        
        //cout<<i<<" "<<m<<" "<<n<<endl;
        
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        
        int op1=solve(b,m,n,i-1,dp);
        int op2=0;
        if(m-b[i].first>=0&&n-b[i].second>=0)
            op2=solve(b,m-b[i].first,n-b[i].second,i-1,dp)+1;
        
        return dp[i][m][n]= max(op1,op2);
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> a;
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<strs.size();i++)
        {
            int x=count(strs[i]);
            a.push_back({x,strs[i].length()-x});
        }
        
        return solve(a,m,n,strs.size()-1,dp);
        
    }
};