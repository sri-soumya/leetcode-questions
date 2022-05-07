class Solution {
public:
    
    vector<int> solve(vector<int> &a,int i,int j)
    {
        vector<int> s,p;
        int n=a.size();
        if(i==n)
            return s;
        
        
        s=solve(a,i+1,j);
        if(j==-1||a[i]%a[j]==0)
        {
            //b.push_back(a[i]);
            
            p=solve(a,i+1,i);
            p.insert(p.begin(),a[i]);
        }
        
        if(s.size()>p.size())
            return s;
        return p;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<int> b,dp(n,0);
        //return solve(a,0,-1);
        
        dp[n-1]=1;
        int in;
        int o=0;
        for(int i=n-2;i>=0;i--)
        {
            int x=0;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]%a[i]==0&&dp[j]>x)
                {
                    x=dp[j];
                }
            }
            
            dp[i]=1+x;
            if(dp[i]>o)
            {
                in=i;
                o=dp[i];
            }
        }
        
        b.push_back(a[in]);
        
        for(int i=in+1;i<n;i++)
        {
            if(dp[i]==dp[in]-1&&a[i]%a[in]==0)
            {
                b.push_back(a[i]);
                in=i;
            }
        }
        
        //reverse(b.begin(),b.end());
        
        return b;
    }
};