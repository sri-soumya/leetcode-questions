class Solution {
public:
    
    static bool compare(string a,string b)
    {
        return a.length()<b.length();
    }
    
    bool check(string a,string b)
    {
        int n=a.length(),m=b.length();
        
        if(m-n!=1)
            return false;
        
        int c=0,i=0,j=0;
        
        while(i<n&&j<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
                c++;
            }
        }
        
        return i==n&&j<=m;
        
    }
    
    int longestStrChain(vector<string>& a) {
        
        int n=a.size();
        sort(a.begin(),a.end(),compare);
        vector<int> dp(n,1);
        int ans=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(check(a[j],a[i]))
                    dp[i]=max(dp[i],dp[j]+1);
            }
            
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};