#define pii pair<int,int>
class Solution {
public:
    
    int solve(vector<int> &nums,int i,int t, map<pii,int> &dp)
    {
        int n=nums.size();
        
        if(i>=n)
        {
            if(!t)
                return 1;
            return 0;
        }
        
        if(dp.count({i,t}))
            return dp[{i,t}];
        
        return dp[{i,t}]= solve(nums,i+1,t+nums[i],dp)+solve(nums,i+1,t-nums[i],dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        map<pii,int> dp;
        return solve(nums,0,target,dp);
        
    }
};