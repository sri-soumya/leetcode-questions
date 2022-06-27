class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& g) {
        
        vector<int> ans;
        if(g.size()==0)
        {
            for(int i=0;i<n;i++)
                ans.push_back(i);
            return ans;
        }
        
        queue<int> q;
        vector<vector<int>> e(n);
        vector<int> inc(n,0),v(n,0);
        
        for(int i=0;i<g.size();i++)
        {
            e[g[i][1]].push_back(g[i][0]);
            inc[g[i][0]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(!inc[i])
                q.push(i);
        }
        
        while(q.size())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            v[node]=1;
            
            for(auto x:e[node])
            {
                if(v[x])
                    continue;
                inc[x]--;
                if(!inc[x])
                    q.push(x);
            }
        }
        
        if(ans.size()!=n)
            ans.clear();
        
        return ans;
        
    }
};