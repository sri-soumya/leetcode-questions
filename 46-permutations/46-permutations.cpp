class Solution {
public:
    
    void solve(vector<int> &nums,vector<vector<int>> &a,int in)
    {
        int n=nums.size();
        if(in>=n)
        {
            a.push_back(nums);
            return;
        }
        
        //a.push_back(nums);
        
        for(int i=in;i<n;i++)
        {
            // if(i==in)
            //     continue;
            swap(nums[in],nums[i]);
            
            solve(nums,a,in+1);
            swap(nums[in],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> a;
        solve(nums,a,0);
        return a;
        
    }
};