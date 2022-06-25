class Solution {
public:
    
    bool check(vector<int> &a,int d,int m)
    {
        int n=a.size(),s=0,c=1;
        
        for(int i=0;i<n;i++)
        {
            s+=a[i];
            if(s>m)
            {
                c++;
                if(c>d)
                    return false;
                s=0;
                i--;
            }
        }
        
        return c<=d;
        
    }
    
    int shipWithinDays(vector<int>& w, int d) {
        
        int s=0;
        for(auto x:w)
            s+=x;
        
        int l=0,u=2*s,ans=0;
        
        while(l<=u)
        {
            int m=l+((u-l)/2);
            if(check(w,d,m))
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