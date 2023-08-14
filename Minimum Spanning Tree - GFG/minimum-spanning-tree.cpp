//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define vi vector<int>
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue<vi,vector<vi>,greater<vi>> q;
        q.push({0,0,-1});
        int c=0;
        vector<bool> v(n,0);
        while(q.size())
        {
            auto t=q.top();
            q.pop();
            
            if(v[t[1]]) continue;
            v[t[1]]=1;
            if(t[2]!=-1) c+=t[0];
            
            for(auto x:adj[t[1]])
            {
                if(!v[x[0]])
                    q.push({x[1],x[0],t[1]});
            }
        }
        
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends