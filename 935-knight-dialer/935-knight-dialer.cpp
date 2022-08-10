#define ll long long int
#define mod 1000000007
class Solution {
public:
    
    ll solve(vector<vector<int>> &a,int n,int i,vector<vector<ll>> &dp)
    {
        if(!n)
            return 1;
        
        if(dp[n][i]!=-1)
            return dp[n][i];
        
        ll ans=0;
        
        for(auto x:a[i])
        {
            ans+=(solve(a,n-1,x,dp))%mod;
        }
        
        return dp[n][i]= ans;
    }
    
    int knightDialer(int n) {
        
        vector<vector<int>> a(10);
        a[0]={4,6};
        a[1]={6,8};
        a[2]={7,9};
        a[3]={4,8};
        a[4]={0,3,9};
        a[5]={};
        a[6]={0,1,7};
        a[7]={2,6};
        a[8]={1,3};
        a[9]={2,4};
        
        ll ans=0;
        
        vector<vector<ll>> dp(n+1,vector<ll>(10,-1));
        
        for(int i=0;i<10;i++)
        {
            ans+=solve(a,n-1,i,dp)%mod;
        }
        
        return ans%mod;
    }
};