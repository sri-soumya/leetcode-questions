class Solution {
public:
    int longestMountain(vector<int>& a) {
     
        int n=a.size();
        int l=1;
        int c=0;
        
        for(int i=1;i<n-1;i++)
        {
            if(a[i-1]<a[i]&&a[i]>a[i+1])
            {
                int r=0,j;
                for(j=i+1;j<n-1;j++)
                {
                    if(a[j]>a[j+1])
                        r++;
                    else
                        break;
                }
                
                c=max(c,l+r+2);
                l=1;
                i=j;
            }
            
            if(a[i]>a[i-1])
                l++;
            else
                l=1;
        }
        
        return c;
        
    }
    
    
};