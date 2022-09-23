#define ll long long int
#define mod 1000000007
class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=log2(i);
            ans=ans<<(x+1);
            ans%=mod;
            ans+=i;
        }
        
        return ans;
    }
};