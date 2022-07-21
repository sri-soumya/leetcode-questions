#define ff first
#define ss second

class Solution {
public:
    
    int solve(vector<vector<pair<int,int>>> &e,int s,int t)
    {
        int n=e.size();
        vector<int> sd(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        sd[s]=0;
        q.push({0,s});
        
        while(q.size())
        {
            int d=q.top().ff;
            int node=q.top().ss;
            
            q.pop();
            
            if(d>sd[node])
                continue;
            
            for(auto x:e[node])
            {
                if(d+x.ss<sd[x.ff])
                {
                    sd[x.ff]=d+x.ss;
                    q.push({sd[x.ff],x.ff});
                }
            }
        }
        
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(sd[i]<=t)
                c++;
        }
        
        return c-1;
    }
    
    
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        
        vector<vector<pair<int,int>>> e(n);
        
        for(int i=0;i<edges.size();i++)
        {
            e[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            e[edges[i][1]].push_back({edges[i][0],edges[i][2]}); 
        }
        
        int mi=INT_MAX,in=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int x=solve(e,i,t);
            if(x<=mi)
            {
                mi=x;
                in=i;
            }
            
        }
        
        return in;
        
    }
};