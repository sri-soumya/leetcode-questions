class Solution {
public:
    void nextPermutation(vector<int>& a) {
        
        int n=a.size();
        
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>=a[i+1])
                continue;
            
            for(int j=n-1;j>i;j--)
            {
                if(a[j]>a[i])
                {
                    swap(a[j],a[i]);
                    reverse(a.begin()+i+1,a.end());
                    return;
                }
            }
        }
        
        reverse(a.begin(),a.end());
        
    }
};