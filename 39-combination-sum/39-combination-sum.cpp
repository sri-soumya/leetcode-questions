class Solution {
public:
    
    void solve(vector<int> a,int t,vector<int> b,vector<vector<int>> &c,int i)
    {
        int n=a.size();
        if(i>=n||t<=0)
        {
            if(!t)
                c.push_back(b);
            return;
        }
        
        solve(a,t,b,c,i+1);
        b.push_back(a[i]);
        solve(a,t-a[i],b,c,i);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> b;
        vector<vector<int>> c;
        solve(candidates,target,b,c,0);
        return c;
    }
};