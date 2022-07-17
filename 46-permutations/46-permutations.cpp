class Solution {
public:
    
    void solve(vector<int> &a,int i,vector<vector<int>> &ans)
    {
        int n=a.size();
        if(i>=n)
        {
            ans.push_back(a);
            return;
        }
        
        for(int j=i;j<n;j++)
        {
            swap(a[i],a[j]);
            solve(a,i+1,ans);
            swap(a[i],a[j]);
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        
        vector<vector<int>> ans;
        solve(a,0,ans);
        
        return ans;
        
    }
};