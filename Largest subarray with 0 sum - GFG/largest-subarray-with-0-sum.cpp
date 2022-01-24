// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        //int n=a.size();
    int b[n];
    b[0]=a[0];
    unordered_map<int,int> x;
    for(int i=1;i<n;i++)
    {
        b[i]=b[i-1]+a[i];
        x[b[i]]=i;
    }

    int ans=(x.count(0))?x[0]+1:0;
    
    for(int i=0;i<n;i++)
    {
        if(x.count(b[i]))
            ans=max(ans,x[b[i]]-i);
    }
    
    return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends