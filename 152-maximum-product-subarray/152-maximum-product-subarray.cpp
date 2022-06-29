class Solution {
public:
    int maxProduct(vector<int>& a) {
        
        int n=a.size(),l=1,r=1,i=0,j=n-1,m=INT_MIN;
        
        while(i<n&&j>=0)
        {
            if(!l)
                l=1;
            if(!r)
                r=1;
            l*=a[i];
            r*=a[j];
            i++;j--;
            m=max(m,max(l,r));
            
        }
        
        return m;
        
    }
};