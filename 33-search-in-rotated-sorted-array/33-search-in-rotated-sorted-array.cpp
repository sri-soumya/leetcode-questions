class Solution {
public:
    int search(vector<int>& a, int t) {
     
        int n=a.size();
        int l=0,u=n-1;
        
        while(l<=u)
        {
            int m=(u+l)/2+0/2;
            //cout<<m<<endl;
            if(a[m]==t)
                return m;
            
            if(a[m]>=a[l])
            {
                if(a[m]>=t&&t>=a[l])
                    u=m-1;
                else
                    l=m+1;
            }
            
            else
            {
                if(a[m]<=t&&t<=a[u])
                    l=m+1;
                else
                    u=m-1;
            }
            
        }
        
        return -1;
        
    }
};