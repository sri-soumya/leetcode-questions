class Solution {
public:
    
    bool check(vector<int> &a,int mi,int m,int k)
    {
        int n=a.size(),c=0,p=-1;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]>mi)
            {
                c+=(i-p-1)/k;
                p=i;
            }
        }
        
        c+=(n-p-1)/k;
        
        return c>=m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int l=INT_MAX,u=INT_MIN,ans=-1,n=bloomDay.size();
        
        for(int i=0;i<n;i++)
        {
            l=min(l,bloomDay[i]);
            u=max(u,bloomDay[i]);
        }
        
        while(l<=u)
        {
            int mi=(l+u)/2;
            
            if(check(bloomDay,mi,m,k))
            {
                ans=mi;
                u=mi-1;
            }
            else
                l=mi+1;
        }
        
        return ans;
    }
};