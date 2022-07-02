// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int a[], int n)
    {
        //code here.
        int l=0,u=n-1;
        
        while(l<=u)
        {
            int m=(l+u)/2;
            if(m%2==0)
            {
                if(a[m]==a[m+1])
                    l=m+1;
                else
                    u=m-1;
            }
            
            else
            {
                if(a[m]==a[m-1])
                    l=m+1;
                else
                    u=m-1;
            }
                
        }
        
        return a[l];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends