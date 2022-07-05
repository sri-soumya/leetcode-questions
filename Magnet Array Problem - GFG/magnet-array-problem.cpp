// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    double check(double mid,double a[],int n)
    {
        double s=0;
        for(int i=0;i<n;i++)
        {
            s+=1.0/(mid-a[i]);
        }
        
        return s;
    }
    
    double search(double l,double u,double m[],int n)
    {
        int i=100000;
        //cout<<l<<": "<<endl;
        while(l<=u&&i)
        {
            i--;
            double mid=(l+u)/2.0;
            double x=check(mid,m,n);
            //cout<<mid<<" "<<x<<endl;
            if(abs(x)<0.00000001)
                return mid;
            else if(x>0)
                l=mid;
            else
                u=mid;
        }
        return 0;
    }
    
    
    void nullPoints(int n, double m[], double ans[])
    {
        // Your code goes here   
        for(int i=0;i<n-1;i++)
        {
            ans[i]=search(m[i],m[i+1],m,n);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends