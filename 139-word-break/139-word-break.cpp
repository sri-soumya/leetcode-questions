class Solution {
public:
    
    bool solve(string &s,map<string,int> &mp,int i,vector<int> &dp)
    {
        int n=s.length();
        if(i==n)
            return true;
        
        if(dp[i]!=-1)
            return dp[i];
        
        bool f=false;
        
        for(int j=i;j<n;j++)
        {
            if(mp.count(s.substr(i,j-i+1))&&solve(s,mp,j+1,dp))
                return dp[i]= true;
        }
        
        return dp[i]= false;
    }
    
    bool wordBreak(string s, vector<string>& a) {
        int n=s.length();
        map<string,int> mp;
        
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=0;i<a.size();i++)
        {
            mp[a[i]]++;
        }
        //return solve(s,mp,0,dp);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(mp.count(s.substr(i,j-i+1))&&dp[j+1])
                {
                    dp[i]=true;
                    break;
                }
            }
            
        }
        
        return dp[0];
        
    }
};