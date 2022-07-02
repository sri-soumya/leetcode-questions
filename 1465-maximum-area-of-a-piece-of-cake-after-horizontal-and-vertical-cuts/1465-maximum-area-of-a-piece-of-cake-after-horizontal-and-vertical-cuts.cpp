#define mod 1000000007

class Solution {
public:
    int maxArea(int he, int w, vector<int>& h, vector<int>& v) {
        
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int n=h.size(),m=v.size();
        int a=(int)max(h[0],he-h[n-1]),b=(int)max(v[0],w-v[m-1]);
        
        for(int i=1;i<n;i++)
            a=max(a,h[i]-h[i-1]);
        
        for(int i=1;i<m;i++)
            b=max(b,v[i]-v[i-1]);
        
       return ((long long int)(a%mod)*(b%mod))%mod;
        
    }
};