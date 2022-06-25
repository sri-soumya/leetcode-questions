class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        
        int n=a.size(),c=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(a[i]<=a[i+1])
                continue;
            if(c)
                return false;
            c++;
            if(i==0||a[i+1]>=a[i-1])
                a[i]=a[i+1];
            else
                a[i+1]=a[i];
        }
        
        return true;
        
    }
};