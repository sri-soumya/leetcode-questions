//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ff first
#define ss second
#define pii pair<int,int>
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        // Code here
        
        vector<int> d(n,INT_MAX);
        d[s]=0;
        priority_queue<pii,vector<pii>,greater<pii>> q;
        q.push({0,s});
        
        while(q.size())
        {
            auto x=q.top();
            q.pop();
            for(auto y:adj[x.ss])
            {
                if(x.ff+y[1]<=d[y[0]])
                {
                    d[y[0]]=x.ff+y[1];
                    q.push({x.ff+y[1],y[0]});
                }
            }
        }
        
        return d;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends