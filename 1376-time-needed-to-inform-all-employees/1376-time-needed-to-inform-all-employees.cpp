class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& in) {
        
       queue<pair<int,int>> q;
       int ans=0;
       unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++)
            mp[m[i]].push_back(i);
        
        q.push({h,in[h]});
        
        while(q.size())
        {
            int c=0;
            int l=q.size();
            
            for(int i=0;i<l;i++)
            {
                int x=q.front().first;
                int s=q.front().second;
                q.pop();
                ans=max(ans,s);
                
                for(auto y:mp[x])
                {
                    q.push({y,s+in[y]});
                }
            }
            
            //ans+=c;
        }
        
        return ans;
    }
};