// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &a, int n, int m)
        {
            // your code here
            int ans=-1,l=-1;
            for(int i=0;i<n;i++)
            {
                int x=lower_bound(a[i].begin(),a[i].end(),1)-a[i].begin();
                x=m-x;
                if(x>l)
                {
                    ans=i;
                    l=x;
                }
            }
            
            return ans;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends