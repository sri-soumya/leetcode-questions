class Solution {
public:
    
    vector<vector<int>> solve(vector<int> a,int t,vector<int>b,vector<vector<int>> c,int in)
    {
        if(t<=0||in>=a.size())
        {
            if(t==0)
            {
                c.push_back(b);
                //cout<<c.size()<<endl;
            }
            return c;
        }
        
        vector<vector<int>> d,e,f;
        d=solve(a,t,b,c,in+1);
        b.push_back(a[in]);
        e=solve(a,t-a[in],b,c,in);
        //f=solve(a,t-a[in],b,c,in+1);
        
        c.insert(c.end(),e.begin(),e.end());
        c.insert(c.end(),f.begin(),f.end());
        c.insert(c.end(),d.begin(),d.end());
        
        return c;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> b;
        vector<vector<int>> c;
        return solve(candidates,target,b,c,0);
    }
};