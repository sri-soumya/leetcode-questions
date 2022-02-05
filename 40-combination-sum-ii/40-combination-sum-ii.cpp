class Solution {
public:
    
    void solve(vector<int> a,int t,int in,vector<vector<int>> &b,vector<int> c)
    {
        int n=a.size();
        if(in>=n||t<=0)
        {
            if(!t)
                b.push_back(c);
            return;
        }
        
        int j=in+1;
        for(;j<n;j++)
            if(a[j]!=a[j-1])
                break;
        
        vector<vector<int>> d;
        solve(a,t,j,b,c);
        
        c.push_back(a[in]);
        solve(a,t-a[in],in+1,b,c);
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> b;
        vector<int> c;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,b,c);
        return b;
        
    }
};