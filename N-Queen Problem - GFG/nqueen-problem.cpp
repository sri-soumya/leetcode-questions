// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:


    bool check(int j,vector<int> &a,int n)
    {
        int i=a.size(),c=i;
        for(int x=0;x<i;x++)
        {
            if(a[x]==j||a[x]+c==j||a[x]-c==j)
                return false;
            c--;
        }
        
        //int x=i-1,y=j-1;
        return true;
    }

    void solve(int i,int n,vector<int> &a,vector<vector<int>> &b)
    {
        if(i>n)
        {
            if(a.size()==n)
                b.push_back(a);
            return;
        }
        
        for(int j=1;j<=n;j++)
        {
            if(check(j,a,n))
            {
                a.push_back(j);
                solve(i+1,n,a,b);
                a.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<vector<int>> ans;
        vector<int> a;
        
        solve(1,n,a,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends