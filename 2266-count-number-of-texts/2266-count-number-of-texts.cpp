#define ll long long int
#define mod 1000000007
class Solution {
public:
    
    ll solve(int n,int x,vector<vector<ll>> &dp)
    {
        
        if(n<0)
            return 0;
        
        if(n<=2)
            return n;
        
        if(n==3)
            return 4;
        
        if(n==4&&(x==7||x==9))
            return 8;
        
        
        if(dp[n][x]!=-1)
            return dp[n][x];
        
        ll c=0;
        if(x!=7&&x!=9)
        {
            for(int i=1;i<=3;i++)
                c+=solve(n-i,x,dp);
        }
        else
            for(int i=1;i<=4;i++)
                c+=solve(n-i,x,dp);
        
        return dp[n][x]= c%mod;
    }
    
    ll countTexts(string a) {
        
        ll p=1;
        //cout<<a.length()<<endl;
        
        char c=a[0];
        int i=1,n=a.length();
        vector<vector<ll>> dp(n+1,vector<ll>(10,-1));
        int x=1;
        while(i<n)
        {
            if(a[i]==c)
                x++;
            else
            {
                //cout<<x<<" ";
                p=p*(solve(x,(int)(c)-'0',dp)%mod)%mod;
                x=1;
                c=a[i];
            }
            i++;
        }
        
        p=p*(solve(x,(int)(c)-'0',dp)%mod)%mod;
        cout<<p<<endl;
        //cout<<x<<endl;
        return p%mod;
    }
};