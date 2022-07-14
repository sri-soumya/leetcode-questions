class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        
        int n=a.size();
        
        int t=0,b=n-1,l=0,r=n-1;
        
        while(t<b)
        {
            for(int i=0;i<b-t;i++)
            {
                int x=a[t][l+i];
                a[t][l+i]=a[b-i][l];
                a[b-i][l]=a[b][r-i];
                a[b][r-i]=a[t+i][r];
                a[t+i][r]=x;
            }
            
            t++;
            b--;
            l++;
            r--;
        }
        
    }
};