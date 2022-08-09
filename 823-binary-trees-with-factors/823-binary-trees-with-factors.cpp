#define ll long long int
#define mod 1000000007
class Solution {
public:
    
    ll solve(int in,unordered_map<int,int> &mp,vector<int> &arr,vector<ll> &dp)
    {
        ll c=1,x=arr[in];
        if(dp[in]!=-1)
            return dp[in];
        for(int i=2;i<x;i++)
        {
            if(mp.count(i)&&mp.count(x/i)&&x%i==0)
                c+=(solve(mp[i],mp,arr,dp)*solve(mp[x/i],mp,arr,dp))%mod;
        }
        
        return dp[in]=c%mod;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();ll ans=0;
        sort(arr.begin(),arr.end());
        vector<ll> dp(n,0);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            ll c=1;
            for(int j=2;j<=sqrt(arr[i]);j++)
            {
                if(arr[i]%j==0&&mp.count(j)&&mp.count(arr[i]/j))
                {
                    if(j==arr[i]/j)
                        c+=(dp[mp[j]]*dp[mp[arr[i]/j]])%mod;
                    else
                        c+=(dp[mp[j]]*dp[mp[arr[i]/j]])%mod+(dp[mp[j]]*dp[mp[arr[i]/j]])%mod;
                        
                }
            }
            dp[i]=c;
            ans+=c%mod;
        }
        
        return ans%mod;
    }
};