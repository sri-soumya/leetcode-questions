// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int assignMiceHoles(int n , int m[] , int h[]) {
        // code here
        
        sort(m,m+n);
        sort(h,h+n);
        
        int ans=0;
        
        for(int i=0;i<n;i++)
            ans=max(ans,abs(m[i]-h[i]));
            
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        
        int M[N],H[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>M[i];
        for(int i=0 ; i<N ; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.assignMiceHoles(N,M,H) << endl;
    }
    return 0;
}  // } Driver Code Ends