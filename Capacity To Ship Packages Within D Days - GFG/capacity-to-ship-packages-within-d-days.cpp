// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool check(int a[],int m,int d,int n)
    {
        int c=1,s=0;
        
        for(int i=0;i<n;i++)
        {
           if(a[i]>m)
                return false;
            s+=a[i];
            if(s>m)
            {
                c++;
                s=a[i];
            }
        }
        
        return c<=d;
    }
  
    int leastWeightCapacity(int a[], int n, int d) {
        // code here
        
        int ans=-1,l=0,u=0;
        for(int i=0;i<n;i++)
            u+=a[i];
        
        while(l<=u)
        {
            int m=(l+u)/2;
            if(check(a,m,d,n))
            {
                ans=m;
                u=m-1;
            }
            else
                l=m+1;
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends