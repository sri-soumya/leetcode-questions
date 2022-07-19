class Solution {
public:
    
    bool solve(vector<vector<int>>& a,int i,vector<int> &b)
    {
        
        if(a[i].size()==0)
        {
            b[i]=1;
            return true;
        }
        
        if(b[i]!=-1)
            return b[i];
        
        b[i]=0;
        bool f=true;
        
        for(auto x:a[i])
        {
            if(!solve(a,x,b))
            {
                f=false;
                break;
            }
        }
        return b[i]=f;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& a) {
        
        int n=a.size();
        vector<int> ans;
        //vector<int> v(n,0);
        vector<int> b(n,-1);
        map<int,int> mp;
        
        
        for(int i=0;i<n;i++)
        {
            if(b[i]==-1)
                solve(a,i,b);
            if(b[i]==1)
                ans.push_back(i);
        }
        
        return ans;
    }
};