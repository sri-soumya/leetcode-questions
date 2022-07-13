class Solution {
public:
    
    int parent(int x,vector<int> &p)
    {
        if(p[x]==x)
            return x;
        
        return p[x]=parent(p[x],p);
    }
    
    void Union(int a,int b,vector<int> &p,vector<int> &r)
    {
        int pa=parent(a,p),pb=parent(b,p);
        
        if(pa==pb)
            return;
        
        if(r[pa]<r[pb])
        {
            p[pa]=pb;
        }
        
        else if(r[pb]<r[pa])
        {
            p[pb]=pa;
        }
        
        else
        {
            r[pa]++;
            p[pb]=pa;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& a) {
        
        int m=a.size();
        
        if(m<n-1)
            return -1;
        
        vector<int> p(n,0),r(n,1);
        
        for(int i=0;i<n;i++)
            p[i]=i;
        
        for(int i=0;i<m;i++)
        {
            Union(a[i][0],a[i][1],p,r);
        }
        
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            if(p[i]==i)
                c++;
        }
        
        return c-1;
        
    }
};