// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int a[], int b[]) {
        // code here
        
        vector<vector<int>> e1(n+1),e2(n+1);
        
        for(int i=0;i<e*2;i+=2)
        {
            e1[a[i]].push_back(a[i+1]);
            e2[b[i]].push_back(b[i+1]);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(e1[i].size()!=e2[i].size())
                return false;
            int m=e1[i].size();
            for(int j=0;j<m;j++)
            {
                if(e1[i][j]!=e2[i][m-1-j])
                    return false;
            }
        }
        
        return true;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends