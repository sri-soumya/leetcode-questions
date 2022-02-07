// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.


bool isvalid(bool a[101][101],vector<int>& v,int in,int c,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[in][i]==0)
            continue;
        if(v[i]==c)
            return false;
    }
    
    return true;
}

bool solve(bool a[101][101],vector<int>& v,int in,int m,int n)
{
    //int n=a.size();
    if(in>=n)
        return true;
    
    for(int i=0;i<m;i++)
    {
        if(isvalid(a,v,in,i,n))
        {
            v[in]=i;
            if(solve(a,v,in+1,m,n))
                return true;
            v[in]=-1;
        }
    }
    
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> v(V,-1);
    return (solve(graph,v,0,m,V));
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