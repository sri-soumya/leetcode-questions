//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool solve(bool graph[101][101], int m, int n, int i, vector<int> &f)
    {
        if(i>=n) return 1;
        for(int x=0;x<m;x++)
        {
            bool ff=1;
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]&&f[j]==x)
                {
                    ff=0;
                    break;
                }
            }
            if(!ff) continue;
            f[i]=x;
            if(solve(graph,m,n,i+1,f)) return 1;
            f[i]=-1;
        }
        
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> f(n,-1);
        return solve(graph,m,n,0,f);
    }
};

//{ Driver Code Starts.

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
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends