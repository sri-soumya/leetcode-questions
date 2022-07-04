// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        
        int m=(1ll<<(r-l+1))-1;
        //cout<<m<<endl;
        m=m<<(l-1);
        //cout<<y<<" "<<m<<endl;
        m=y&m;
        //cout<<m<<endl;
        return m|x; 
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}  // } Driver Code Ends