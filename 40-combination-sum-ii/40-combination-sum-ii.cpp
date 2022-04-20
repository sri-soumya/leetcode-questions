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
        
        int j=i+1;
        for(;j<n;j++)
            if(a[j]!=a[j-1])
                break;
        solve(a,t,b,c,j);
        b.push_back(a[i]);
        solve(a,t-a[i],b,c,i+1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        vector<int> b;
        vector<vector<int>> c;
        solve(a,target,b,c,0);
        return c;
    }
};