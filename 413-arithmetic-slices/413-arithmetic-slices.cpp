class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& a) {
     
        int n=a.size();
        
        if(n<3)
            return 0;
        
        vector<int> b;
        int d=a[1]-a[0];
        int c=2;
        
        for(int i=2;i<n;i++)
        {
            if(a[i]-a[i-1]==d)
                c++;
            else
            {
                b.push_back(c);
                c=2;
                d=a[i]-a[i-1];
            }
        }
        
        b.push_back(c);
        
        int s=0;
        for(int i=0;i<b.size();i++)
        {
            s+=(b[i]*(b[i]+1))/2-(2*b[i]-1);
        }
        return s;
        
    }
};