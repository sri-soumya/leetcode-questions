// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool solve(bool graph[101][101],int m,int n,int i,vector<int>& b)
{
   
    if(i>=n)
    {
        return true;
    }
        
        
    for(int x=1;x<=m;x++)
    {
        // cout<<i<<" "<<x<<endl;
        bool f=true;
        for(int j=0;j<n;j++)
        {
            if((graph[i][j])&&b[j]==x)
            {
                //cout<<i<<" "<<x<<endl;
                f=false;
                //break;
            }
        }
        
        if(f)
        {
            //cout<<i<<" "<<x<<endl;
            b[i]=x;
            bool ff=solve(graph,m,n,i+1,b);
            if(ff)
                return true;
            b[i]=0;
        }
    }
    
    return false;
    
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> b(n,0);
    return solve(graph,m,n,0,b);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends