class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        
        int n=a.size();
        bool l=true;
        
        for(int i=1;i<n-1;i++)
        {
            if(a[i]<=a[i-1])
                return false;
            
            if(a[i]>a[i+1])
            {
                cout<<i<<endl;
                for(;i<n-1;i++)
                {
                    if(a[i+1]>=a[i])
                        return false;
                }
                
                return true;
            }
        }
        
        return false;
        
    }
};