//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool ispal(string &s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }

    int solve(string &s, int i, vector<int> &dp)
    {
        int n=s.size(),ans=INT_MAX;
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<n;j++)
        {
            if(ispal(s,i,j))
                ans=min(ans,solve(s,j+1,dp)+1);
        }
        
        return dp[i]= ans;
    }

    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int> dp(n+1,1e7);
        // return solve(str,0,dp)-1;
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int ans=1e7;
            for(int j=i;j<n;j++)
            {
                if(ispal(str,i,j))
                    ans=min(ans,dp[j+1]+1);
            }
            dp[i]=ans;
        }
        
        return dp[0]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends