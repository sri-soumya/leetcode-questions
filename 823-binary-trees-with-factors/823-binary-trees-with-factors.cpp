#define ll long long int
#define mod 1000000007
class Solution {
public:
   
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
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0&&mp.count(arr[i]/arr[j]))
                    c+=(dp[j]*dp[mp[arr[i]/arr[j]]])%mod;
            }
            
            dp[i]=c;
            ans+=c%mod;
        }
        
        return ans%mod;
    }
};