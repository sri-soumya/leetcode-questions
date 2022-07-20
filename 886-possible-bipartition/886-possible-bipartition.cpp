class Solution {
public:
    
     bool dfs(vector<vector<int>> &a,vector<int> &v,int i,int c)
     {
         v[i]=c;
         
         int nc;
         if(c==1)
             nc=2;
         else
             nc=1;
         
         for(auto x:a[i])
         {
             if(v[x]==v[i])
                 return false;
             else if(!v[x]&&!dfs(a,v,x,nc))
                 return false;
                 
         }
         
         return true;
     }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& a) {
        
        int m=a.size();
        
        vector<int> v(n+1,0);
        
        vector<vector<int>> e(n+1);
        
        for(int i=0;i<m;i++)
        {
            e[a[i][0]].push_back(a[i][1]);
            e[a[i][1]].push_back(a[i][0]);
            
        }
        
        for(int i=1;i<=n;i++)
        {
            if(!v[i]&&!dfs(e,v,i,1))
                return false;
        }
        
        return true;
    }
};