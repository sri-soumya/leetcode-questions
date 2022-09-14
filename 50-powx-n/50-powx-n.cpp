class Solution {
public:
    
    double solve(double x,int n)
    {
        if(!n)
            return 1;
        double a=solve(x,n/2);
        a*=a;
        if(n%2)
            a*=x;
        return a;
    }
    
    double myPow(double x, int n) {
        double ans=solve(x,abs(n));
        if(n<0)
            return 1/ans;
        return ans;
    }
};