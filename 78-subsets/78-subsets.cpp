class Solution {
public:
    
    void solve(vector<int> nums,vector<vector<int>> &a,vector<int> b,int in)
    {
        int n=nums.size();
        if(in>=n)
        {
            a.push_back(b);
            return;
        }
        
        solve(nums,a,b,in+1);
        b.push_back(nums[in]);
        solve(nums,a,b,in+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> a;
        vector<int> b;
        solve(nums,a,b,0);
        return a;
    }
};