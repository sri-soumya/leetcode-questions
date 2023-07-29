//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int a[], int i, int j, vector<vector<int>> &dp)
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
            ans=min(ans,a[i-1]*a[k]*a[j]+solve(a,i,k,dp)+solve(a,k+1,j,dp));
        return dp[i][j]= ans;
    }

    int matrixMultiplication(int n, int a[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,0));
        // return solve(a,1,n-1,dp);
        for(int i=n-1;i>=1;i--)
        {
            
            for(int j=i+1;j<n;j++)
            {
                // if(i==j) continue;
                int ans=INT_MAX;
                for(int k=i;k<j;k++)
                    ans=min(ans,a[i-1]*a[k]*a[j]+dp[i][k]+dp[k+1][j]);
                dp[i][j]=ans;
            }
            
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends