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
        int pa=parent(a,p);
        int pb=parent(b,p);
        
        if(pa==pb)
            return;
        
        if(r[pa]<r[pb])
            p[pa]=pb;
        else if(r[pb]<r[pa])
            p[pb]=pa;
        else
        {
            r[pa]++;
            p[pb]=pa;
        }
    }
    
    
    bool equationsPossible(vector<string>& a) {
        
        int n=a.size();
        vector<int> p(26,0),r(26,1);
        
        for(int i=0;i<26;i++)
            p[i]=i;
        
        for(int i=0;i<n;i++)
        {
            if(a[i][1]=='!')
                continue;
            
            Union(a[i][0]-'a',a[i][3]-'a',p,r);
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i][1]=='=')
                continue;
            
            int pa=parent(a[i][0]-'a',p);
            int pb=parent(a[i][3]-'a',p);
            
            if(pa==pb)
                return false;
        }
        
        return true;
    }
};