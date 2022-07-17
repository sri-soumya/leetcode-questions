class Solution {
public:
    
    void solve(unordered_map<int,int> &mp, vector<int> &b,vector<vector<int>> &ans,int n)
    {
        int m=b.size();
        
        if(n==m)
        {
            ans.push_back(b);
            return;
        }
        
        for(auto &x:mp)
        {
            if(x.second==0)
                continue;
            x.second--;
            b.push_back(x.first);
            solve(mp,b,ans,n);
            b.pop_back();
            x.second++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& a) {
        
        int n=a.size();
        vector<int> b;
        vector<vector<int>> ans;
        
        unordered_map<int,int> mp;
        for(auto x:a)
            mp[x]++;
        
        solve(mp,b,ans,n);
        
        return ans;
    }
};