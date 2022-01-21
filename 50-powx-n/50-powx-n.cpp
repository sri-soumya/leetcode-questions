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
    
    double myPow(double x, int m) {
        
        //return solve(x,n);
        if(m==0)
            return 1.0;
        
        long long n=abs(m);
        
        double ans=1.0;
        
        while(n>0)
        {
            if(n%2)
            {
                n--;
                ans*=x;
            }
            
            else
            {
                n/=2;
                x*=x;
            }
        }
        
        if(m<0)
            ans=1/ans;
        
        return ans;
        
        
    }
};