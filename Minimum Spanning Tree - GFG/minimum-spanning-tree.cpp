//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	int parent(int x, vector<int> &p)
	{
	    if(x==p[x]) return x;
	    return p[x]=parent(p[x],p);
	}
	
	void Union(int a, int b, vector<int> &p, vector<int> &rank)
	{
	    if(rank[a]>rank[b]) p[b]=a;
	    else if(rank[b]>rank[a]) p[a]=b;
	    else
	    {
	        p[b]=a;
	        rank[a]++;
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>> e;
        vector<int> p(n),rank(n,1);
        
        for(int i=0;i<n;i++) p[i]=i;
        
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i])
            {
               e.push_back({x[1],i,x[0]}); 
            }
                
        }
        
        sort(e.begin(),e.end());
        
        for(auto x:e)
        {
            int p1=parent(x[1],p),p2=parent(x[2],p);
            if(p1!=p2)
            {
                Union(p1,p2,p,rank);
                c+=x[0];
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