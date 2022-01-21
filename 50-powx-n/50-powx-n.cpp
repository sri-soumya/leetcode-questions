class Solution {
public:
    
    double solve(double x,int n)
    {
        if(n==0)
            return 1.0;
        if(n<0)
        {
            x=1/x;
            n=abs(n);
        }
        
        double a=solve(x,n/2);
        a*=a;
        
        if(n%2)
            a*=x;
        
        return a;
    }
    
    double myPow(double x, int n) {
        
        return solve(x,n);
        
    }
};