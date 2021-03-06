class Solution {
public:
    
    bool check(string s)
    {
        int x=stoi(s);
        return x>0&&x<=26;
    }
    
    int solve(string &s,int i,vector<int> &dp)
    {
        int n=s.length();
        if(i>n||s[i]=='0')
            return 0;
        
        if(i==n)
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=0;
        
        for(int j=1;j<=2;j++)
        {
            if(i+j>n)
                break;
            if(check(s.substr(i,j)))
            {
                int y=solve(s,i+j,dp);
               ans+=y;
            }
        }
        
        return dp[i]= ans;       
    }
    
    int numDecodings(string s) {
        
        int n=s.length();
        
        vector<int> dp(n+1,0);
        
        //return solve(s,0,dp);
        
        dp[n]=1;
        
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]=='0')
        //         dp[i]=0;
        // }
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
                continue;
            
            int ans=0;
            for(int j=1;j<=2;j++)
            {
                if(i+j>n)
                    break;
                if(check(s.substr(i,j)))
                    ans+=dp[i+j];
            }
            
            dp[i]=ans;
        }
        
        return dp[0];
    }
};