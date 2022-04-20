class Solution {
public:
    
    void solve(vector<int> a,vector<int> b,vector<vector<int>> &c,int i)
    {
        int n=a.size();
        if(i>=n)
        {
            c.push_back(b);
            return;
        }
        
        int j=i+1;
        for(;j<n;j++)
            if(a[j]!=a[j-1])
                break;
        solve(a,b,c,j);
        b.push_back(a[i]);
        solve(a,b,c,i+1);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> b;
        vector<vector<int>> c;
        sort(nums.begin(),nums.end());
        solve(nums,b,c,0);
        return c;
    }
};