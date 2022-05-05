class Solution {
public:
    
    void solve(vector<vector<int>> &a,vector<int> b,vector<int> c,int i,int t)
    {
        
        if(t<0)
            return;
        
        if(i<0||!t)
        {
            if(!t)
                a.push_back(b);
            return;
        }
        
        solve(a,b,c,i-1,t);
        b.push_back(c[i]);
        solve(a,b,c,i,t-c[i]);
        //b.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> a;
        vector<int> b;
        
        solve(a,b,c,c.size()-1,t);
        return a;
    }
};