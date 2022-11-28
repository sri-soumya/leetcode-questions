class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> mp;
        
        for(auto x:matches)
        {
            mp[x[0]]=0;
            mp[x[1]]=0;
        }
        
        for(auto x:matches)
        {
            mp[x[1]]++;
        }
        
        for(auto x:mp)
        {
            if(x.second==0)
                ans[0].push_back(x.first);
            if(x.second==1)
                ans[1].push_back(x.first);
        }
        
        return ans;
    }
};