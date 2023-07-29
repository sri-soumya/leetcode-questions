//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int a[], int i, int n,vector<int> &dp)
	{
	    if(i>=n) return 0;
	   // int op1=solve(a,i+1,n);
	   if(dp[i]!=-1) return dp[i];
	    int op2=0;
	    
	    for(int j=i+1;j<n;j++)
	    {
	        if(a[j]>a[i]) 
	            op2=max(op2,solve(a,j,n,dp));
	    }
	    
	    return dp[i]= op2+a[i];
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n,-1);
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        ans=max(ans,solve(arr,i,n,dp));
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends