#define ll long long int
class Solution {
public:
    
    bool check(vector<int> &a,int m,int x)
    {
        ll c=0,n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]%m)
                c+=a[i]/m+1;
            else
                c+=a[i]/m;
        }
        
        return c<=x;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size(),l=1,u=0,ans=0;
        
        for(int i=0;i<n;i++)
            u=max(u,piles[i]);
        
        while(l<=u)
        {
            int m=(l+u)/2;
            if(check(piles,m,h))
            {
                ans=m;
                u=m-1;
            }
            else
                l=m+1;
        }
        
        return ans;
    }
};