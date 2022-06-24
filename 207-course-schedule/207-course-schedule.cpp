class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> e(n);
        vector<int> ind(n,0);
        queue<int> q;
        int m=edges.size();
        
        for(int i=0;i<m;i++)
        {
            e[edges[i][0]].push_back(edges[i][1]);
            ind[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
                q.push(i);
        }
        
        int c=0;
        
        while(q.size())
        {
            int i=q.front();
            q.pop();
            c++;
            
            for(auto x:e[i])
            {
                ind[x]--;
                if(ind[x]==0)
                    q.push(x);
            }
        }
        
        return c==n;
        
    }
};