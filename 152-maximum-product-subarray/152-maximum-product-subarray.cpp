class Solution {
public:
    

    int maxProduct(vector<int>& a) {
     
        int n=a.size(),i=0,j=n-1,l=1,r=1,ans=INT_MIN;
        
        while(i<n&&j>=0)
        {
            if(!l)
                l=1;
            if(!r)
                r=1;
            l*=a[i];
            r*=a[j];
            ans=max(ans,max(l,r));
            i++;j--;
        }
        
        return ans;
        
    }
};