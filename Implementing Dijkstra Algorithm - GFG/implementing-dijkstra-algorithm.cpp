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
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int so)
    {
        // Code here
        
        vector<int> d(n,INT_MAX);
        d[so]=0;
        set<pii> s;
        s.insert({0,so});
        
        while(s.size())
        {
            auto x=*s.begin();
            s.erase(x);
            
            int in=x.ss,di=x.ff;
            for(auto y:adj[in])
            {
                if(di+y[1]<d[y[0]])
                {
                    if(d[y[0]]!=INT_MAX) s.erase({d[y[0]],y[0]});
                    d[y[0]]=di+y[1];
                    s.insert({d[y[0]],y[0]});
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