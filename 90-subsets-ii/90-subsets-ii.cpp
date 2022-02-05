class Solution {
public:
    
    vector<vector<int>> solve(vector<int> a,int i,vector<vector<int>> b,vector<int> c)
    {
        int n=a.size();
        
        if(i>=n)
        {
            b.push_back(c);
            return b;
        }
        int j=i+1;
        for(;j<n;j++)
            if(a[j]!=a[j-1])
                break;
        vector<vector<int>> d,e;
        //if(i==0||a[i]!=a[i-1])
        d=solve(a,j,b,c);
        c.push_back(a[i]);
        e=solve(a,i+1,b,c);
        
        d.insert(d.end(),e.begin(),e.end());
        return d;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> a;
        vector<int> c;
        sort(nums.begin(),nums.end());
        return solve(nums,0,a,c);
    }
};