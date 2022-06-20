class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& a) {
     
        int n=a.size(),s=0;
        
        if(n<3)
            return 0;
        int d=a[1]-a[0];
        int c=2;
        
        for(int i=2;i<n;i++)
        {
            if(a[i]-a[i-1]==d)
                c++;
            else
            {
                //b.push_back(c);
                s+=(c*(c+1))/2-(2*c-1);
                c=2;
                d=a[i]-a[i-1];
            }
        }
        s+=(c*(c+1))/2-(2*c-1);
        
        return s;
    }
};