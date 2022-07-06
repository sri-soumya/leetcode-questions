class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        
        int n=a.size();
        int d=INT_MAX,s=0;
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                int di=abs(a[i]+a[j]+a[k]-t);
                if(di<d)
                {
                    s=a[i]+a[j]+a[k];
                    d=di;
                }
                
                int ss=a[i]+a[j]+a[k];
                if(ss<t)
                    j++;
                else if(ss>t)
                    k--;
                else
                    return ss;
                    
            }
        }
        
        return s;
    }
};