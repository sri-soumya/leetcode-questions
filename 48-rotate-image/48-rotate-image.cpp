class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        
        int n=a.size();
        int l=0,t=0,r=n-1,b=n-1;
        
        while(l<r)
        {
            for(int i=0;i<r-l;i++)
            {
                int x=a[t][l+i];
                a[t][l+i]=a[b-i][l];
                a[b-i][l]=a[b][r-i];
                a[b][r-i]=a[t+i][r];
                a[t+i][r]=x;
            }
            
            l++;t++;r--;b--;
        }
        
    }
};