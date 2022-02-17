class Solution {
public:
    
    void solve(vector<int> c,vector<vector<int>> &a,vector<int> b,int t,int in)
    {
        int n=c.size();
        if(!t)
        {
            a.push_back(b);
            return;
        }
        if(in>=n||t<0)
            return;
        
        solve(c,a,b,t,in+1);
        b.push_back(c[in]);
        solve(c,a,b,t-c[in],in);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> a;
        vector<int> b;
        solve(candidates,a,b,target,0);
        return a;
    }
};