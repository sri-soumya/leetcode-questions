// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int kadane(vector<int> &a)
    {
        int m=INT_MIN;
        int n=a.size(),s=0;
        
        for(int i=0;i<n;i++)
        {
            s+=a[i];
            m=max(m,s);
            if(s<0)
                s=0;
        }
        
        return m;
    }
  
    int maximumSumRectangle(int m, int n, vector<vector<int>> a) {
        // code here
        int ans=INT_MIN;
        for(int k=0;k<m;k++)
        {
            vector<int> b(n,0);
            for(int i=k;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    b[j]+=a[i][j];
                ans=max(ans,kadane(b));
            }
            
            
        }
        
        return ans;
        
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends