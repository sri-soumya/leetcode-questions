class Solution {
public:
    
    int fparent(int x,vector<int> &parent)
    {
        if(parent[x]==x)
            return x;
        
        return parent[x]=fparent(parent[x],parent);
    }
    
    void Union(int a,int b,vector<int> &parent,vector<int> &rank)
    {
        int pa=fparent(a,parent);
        int pb=fparent(b,parent);
        
        if(pa==pb)
            return;
        
        if(rank[pa]>rank[pb])
        {
            parent[pb]=pa;
        }
        
        else if(rank[pb]>rank[pa])
        {
            parent[pa]=pb;
        }
        
        else
        {
            rank[pa]++;
            parent[pb]=pa;
        }
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        
        int n=a.size();
        vector<int> parent(n,0),rank(n,1);
        
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j])
                    Union(i,j,parent,rank);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                c++;
        }
        
        return c;
    }
};