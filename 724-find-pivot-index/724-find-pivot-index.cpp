class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n=a.size();
        
        int r=0,l=0;
        for(int i=0;i<n;i++)
            r+=a[i];
        
       for(int i=0;i<n;i++)
       {
           r-=a[i];
           if(l==r)
               return i;
           l+=a[i];
       }
        
        return -1;
        
    }
};