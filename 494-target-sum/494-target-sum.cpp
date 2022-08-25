class Solution {
public:
    
    int solve(vector<int> &nums,int i,int t)
    {
        int n=nums.size();
        
        if(i>=n)
        {
            if(!t)
                return 1;
            return 0;
        }
        return solve(nums,i+1,t+nums[i])+solve(nums,i+1,t-nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,0,target);
        
    }
};