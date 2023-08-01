//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, vector<string> &ans, string &a, int i, int j)
    {
        int n=m.size();
        if(i<0||j<0||i>=n||j>=n||m[i][j]==-1||m[i][j]==0) return;
        if(i==n-1&&j==n-1)
        {
            ans.push_back(a);
            return;
        }
        m[i][j]=-1;
        a+='D';
        solve(m,ans,a,i+1,j);
        a.pop_back();
        
        a+='L';
        solve(m,ans,a,i,j-1);
        a.pop_back();
        
        a+='R';
        solve(m,ans,a,i,j+1);
        a.pop_back();
        
        a+='U';
        solve(m,ans,a,i-1,j);
        a.pop_back();
        
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string a="";
        solve(m,ans,a,0,0);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends