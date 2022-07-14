class Solution {
public:
    int findDuplicate(vector<int>& a) {
        
        int n=a.size();
        
        for(int i=0;i<n;i++)
        {
            int x=abs(a[i]);
            
            if(a[x]<0)
                return x;
            
            a[x]*=-1;
        }
        
        return 0;
        
    }
};