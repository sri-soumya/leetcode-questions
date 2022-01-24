// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int solve(vector<int> nums)
    {
        int n=nums.size(),lb=0,ub=n-1;
        
        while(lb<=ub)
        {
            int m=(lb+ub)/2;
            if(m-1>=0&&nums[m]<nums[m-1])
                return m;
            if(m+1<n&&nums[m]>nums[m+1])
                return m+1;
            if(nums[lb]<nums[m])
                lb=m+1;
            else
                ub=m-1;
        }
        
        return 0;
    }
    
	int findKRotation(int arr[], int n) {
	    // code here
	    vector<int> a;
	    for(int i=0;i<n;i++)
	        a.push_back(arr[i]);
	    return solve(a);
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends