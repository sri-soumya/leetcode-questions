class Solution {
public:
    int mySqrt(int x) {
        
        double l=0,u=x;
        int i=1000;
        double ans=0;
        
        while(l<=u&&--i)
        {
            double m=(l+u)/2.0;
            ans=m;
            if(m*m==x)
                break;
            if(m*m<x)
                l=m;
            else
              u=m;  
        }
        
        return ans;
    }
};