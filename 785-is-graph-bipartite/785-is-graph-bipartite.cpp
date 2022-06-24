class Solution {
public:
    
    bool dfs(vector<vector<int>>& e,vector<int> &v,int i,int c)
    {
        v[i]=c;
        int z;
        if(c==1)
            z=2;
        else
            z=1;
        
        for(auto x:e[i])
        {
            if(!v[x])
            {
                if(!dfs(e,v,x,z))
                    return false;
                
            }
            
            else if(v[x]==c)
                return false;
            
        }
        
        return true;
    }
    
    bool bfs(vector<vector<int>>& e,vector<int> &v,int i)
    {
        
        queue<pair<int,int>> q;
        q.push({i,1});
        
        while(q.size())
        {
            int node=q.front().first,c=q.front().second;
            //cout<<node<<" "<<c<<endl;
            q.pop();
            v[node]=c;
            int z;
            if(c==1)
                z=2;
            else
                z=1;
            
            for(auto x:e[node])
            {
                if(!v[x])
                    q.push({x,z});
                else if(v[x]==c)
                {
                    //cout<<node<<" "<<x<<" "<<c<<endl;
                    return false;
                }
            }
        }
        
        return true;
            
        
    }
    
    bool isBipartite(vector<vector<int>>& e) {
        
        int n=e.size();
        
        vector<int> v(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(v[i]!=0)
                continue;
            int c=bfs(e,v,i);
            if(c==0)
                return false;
        }
        
        return true;
        
    }
};