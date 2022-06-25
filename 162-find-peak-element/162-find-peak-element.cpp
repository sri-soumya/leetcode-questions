class Solution {
public:
    int findPeakElement(vector<int>& a) {
        
        int n=a.size();
        if(n==1)
            return 0;
        if(a[0]>a[1])
            return 0;
        
        int l=0,u=n-1;
        
        while(l<=u)
        {
            int m=l+(u-l)/2;
            int le=(m-1>=0)?a[m-1]:INT_MIN;
            int ri=(m+1<n)?a[m+1]:INT_MIN;
            
            if(a[m]>le&&a[m]>ri)
                return m;
            if(le>a[m])
                u=m-1;
            else
                l=m+1;
        }
            
        return n-1;
        
    }
};