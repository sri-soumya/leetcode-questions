// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int a1[], int a2[], int n) {
            // code here 
            
        if(n==1)
            return a1[0]+a2[0];
        int l=0,u=n-1;
        
        while(l<=u)
        {
            int m=(l+u)/2;
            int n1=m;
            int n2=n-n1;
            int l1=(m-1>=0)?a1[m-1]:INT_MIN;
            int l2=(n2>0)?a2[n2-1]:INT_MIN;
            int r1=(n1<n)?a1[n1]:INT_MAX;
            int r2=(n2<n)?a2[n2]:INT_MAX;
            
            if(l1>r2)
                u=m-1;
            else if(l2>r1)
                l=m+1;
            else return (max(l1,l2)+min(r1,r2));
        }
        
        return 0;    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends