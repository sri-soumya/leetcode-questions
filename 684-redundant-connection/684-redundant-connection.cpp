class Solution {
public:
    
    int parent(int x,vector<int> &p)
    {
        if(p[x]==x)
            return x;
        
        return p[x]=parent(p[x],p);
    }
    
    void Union(int a,int b,vector<int> &r,vector<int> &p)
    {
        if(r[a]>r[b])
            p[b]=a;
        else if(r[b]>r[a])
            p[a]=b;
        else
        {
            r[a]++;
            p[b]=a;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& a) {
        
        int n=a.size();
        
        vector<int> p(n+1,0),r(n+1,1);
        for(int i=0;i<=n;i++)
            p[i]=i;
        
        for(int i=0;i<n;i++)
        {
            int pa=parent(a[i][0],p);
            int pb=parent(a[i][1],p);
            
            if(pa==pb)
                return a[i];
            
            Union(pa,pb,r,p);
        }
        
        return {0,0};
    }
};