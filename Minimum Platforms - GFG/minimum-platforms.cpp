// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int at[], int dt[], int n)
    {
    	// Your code here
        priority_queue<int,vector<int>,greater<int>> q;
        int c=0;
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
            a.push_back({at[i],dt[i]});
        
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            if(!q.size()||a[i].first<=q.top())
            {
                c++;
                q.push(a[i].second);
            }
            else
            {
                q.pop();
                q.push(a[i].second);
            }
        }
        
        return c;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends