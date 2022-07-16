#define mod 1000000007
#define ll long long int
#define ff first
#define ss second
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& a) {
        
        vector<vector<vector<int>>> e(n);
        
        for(auto x:a)
        {
            e[x[0]].push_back({x[1],x[2]});
            e[x[1]].push_back({x[0],x[2]});
            
        }
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
        vector<pair<ll,ll>> d(n,{LONG_MAX,0});
        d[0]={0,1};
        q.push({0,0});
        
        while(q.size())
        {
            ll dd=q.top().ff;
            ll node=q.top().ss;
            q.pop();
            if(dd>d[node].ff)
                continue;
            for(auto x:e[node])
            {
                ll dis=d[node].ff+x[1];
                if(d[x[0]].ff>dis)
                {
                    d[x[0]]={dis,d[node].ss};
                    q.push({dis,x[0]});
                }
                
                else if(d[x[0]].ff==dis)
                {
                    d[x[0]].ss+=d[node].ss%mod;
                    d[x[0]].ss%=mod;
                    
                    //q.push(x[0]);
                }
            }
        }
        
        return d[n-1].ss%mod;
    }
};