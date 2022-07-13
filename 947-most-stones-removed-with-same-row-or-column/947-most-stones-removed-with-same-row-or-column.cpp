class Solution {
public:
    
    int parent(int x,vector<int> &p,vector<int> &r)
    {
        if(p[x]==-1)
        {
            return p[x]=x;
            r[x]=1;
        }
        if(p[x]==x)
            return x;
        
        return p[x]=parent(p[x],p,r);
    }
    
    void Union(int a,int b,vector<int> &p,vector<int> &r)
    {
        
        int pa=parent(a,p,r),pb=parent(b,p,r);
        if(pa==pb)
            return;
        
        if(r[pa]>r[pb])
            p[pb]=pa;
        else if(r[pb]>r[pa])
            p[pa]=pb;
        else
        {
            r[pa]++;
            p[pb]=pa;
        }
    }
    
    int removeStones(vector<vector<int>>& a) {
        
        int n=a.size();
        
        int c=0,x=0;
        
        vector<int> p(n,0),r(n,1);
        for(int i=0;i<n;i++)
            p[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i][0]==a[j][0]||a[i][1]==a[j][1])
                    Union(i,j,p,r);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(p[i]==i)
                c++;
        }
        
        return n-c;
    }
};