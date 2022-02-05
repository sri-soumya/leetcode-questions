// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    vector<int> solve(vector<int> a,int n,int i,int s,vector<int> b)
    {
        if(i>=n)
        {
            b.push_back(s);
            return b;
        }
        
        vector<int> c,d;
        c=solve(a,n,i+1,s,b);
        d=solve(a,n,i+1,s+a[i],b);
        c.insert(c.end(),d.begin(),d.end());
        
        return c;
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> b;
        return solve(arr,N,0,0,b);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends