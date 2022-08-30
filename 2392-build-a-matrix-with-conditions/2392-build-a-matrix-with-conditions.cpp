class Solution {
public:
    
    vector<int> toposort(vector<vector<int>> &e)
    {
        int n=e.size();
        
        vector<int> in(n,0);
        for(auto x:e)
        {
            for(auto y:x)
                in[y]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(q.size())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x);
            
            for(auto y:e[x])
            {
                in[y]--;
                if(in[y]==0)
                    q.push(y);
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
     
        int n=rc.size(),m=cc.size();
        
        vector<vector<int>> e1(k),e2(k);
        
        for(auto x:rc)
        {
            e1[x[0]-1].push_back(x[1]-1);
        }
        
        for(auto x:cc)
        {
            e2[x[0]-1].push_back(x[1]-1);
        }
        
        vector<int> t1=toposort(e1),t2=toposort(e2);
        
        //cout<<t1.size()<<" "<<t2.size()<<endl;
        
        if(t1.size()!=k||t2.size()!=k)
            return {};
        
        map<int,int> mp;
        for(int i=0;i<k;i++)
        {
            mp[t2[i]]=i;
        }
        
        vector<vector<int>> ans(k,vector<int>(k,0));
        
        for(int i=0;i<k;i++)
        {
            ans[i][mp[t1[i]]]=t1[i]+1;
        }
        
        return ans;
    }
};