class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        
        int n=a.size();
        vector<long long int> p(n,0);
        p[0]=a[0];
        
        for(int i=1;i<n;i++)
            p[i]=a[i]+p[i-1];
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(p[i]<t)
                continue;
            int x=lower_bound(p.begin(),p.end(),p[i]-t)-p.begin();
            int d=i-x+1;
            if(p[x]==p[i]-t)
                d--;
            ans=min(ans,d);
        }
        
        if(ans==INT_MAX)
            return 0;
        return ans;
        
    }
};