class Solution {
public:
    
    static int parent(int x,vector<int> &p)
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
            p[pa]=pb;
        else if(r[pb]<r[pa])
            p[pb]=pa;
        else
        {
            r[pa]++;
            p[pb]=pa;
        }
    }
    
    void sortanddup(vector<vector<string>> &a,int x)
    {
        unordered_map<string,int> mp;
        
        vector<string> b;
        b.push_back(a[x][0]);
        
        for(int i=1;i<a[x].size();i++)
        {
            if(!mp.count(a[x][i]))
                b.push_back(a[x][i]);
            mp[a[x][i]]++;
        }
        
        sort(b.begin()+1,b.end());
        
        a[x]=b;
    }
    
    void merge(vector<vector<string>>& a,int x,int y)
    {
        for(int i=1;i<a[x].size();i++)
        {
                a[y].push_back(a[x][i]);
        }   
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
     
        int n=a.size();
        vector<int> p(n,0),r(n,1);
        
        for(int i=0;i<n;i++)
            p[i]=i;
        
        unordered_map<string,int> mp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<a[i].size();j++)
            {
                if(mp.count(a[i][j]))
                    Union(mp[a[i][j]],i,p,r);
                mp[a[i][j]]=i;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(p[i]==i)
                continue;
            merge(a,i,parent(i,p));
        }
        
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++)
        {
            if(p[i]==i)
            {
                sortanddup(a,i);
                ans.push_back(a[i]);
            }
        }
        
        return ans;
    }
};