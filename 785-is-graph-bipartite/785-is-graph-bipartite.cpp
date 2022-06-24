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
    
    bool isBipartite(vector<vector<int>>& e) {
        
        int n=e.size();
        
        vector<int> v(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(v[i])
                continue;
            if(!dfs(e,v,i,1))
                return false;
        }
        
        return true;
        
    }
};