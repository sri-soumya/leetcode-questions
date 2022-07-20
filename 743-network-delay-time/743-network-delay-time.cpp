class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int m=times.size();
        vector<vector<pair<int,int>>> e(n+1);
        
        for(int i=0;i<m;i++)
        {
            e[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> sd(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        sd[k]=0;
        q.push({0,k});
        
        while(q.size())
        {
            int node=q.top().second;
            int dis=q.top().first;
            q.pop();
            if(sd[node]<dis)
                continue;
            for(auto x:e[node])
            {
                if(sd[x.first]>dis+x.second)
                {
                    sd[x.first]=dis+x.second;
                    q.push({sd[x.first],x.first});
                }
            }
        }
        
        int ans=INT_MIN;
        
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,sd[i]);
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
};