// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *a=new int[2];
        //return a;
        long long int s=0;
        for(int i=0;i<n;i++)
        {
            int x=abs(arr[i]);
            //cout<<x<<endl;
            s+=x;
            if(arr[x-1]<0)
            {
                a[0]=x;
                //break;
            }
            arr[x-1]*=-1;
        }
        //cout<<s<<endl;
        a[1]=(((long long int)n)*(n+1))/2-(s-a[0]);
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends