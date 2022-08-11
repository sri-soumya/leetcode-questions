class Solution {
public:
    
    int solve(vector<int> &nums,int i,vector<int> &dp)
    {
        int n=nums.size();
        if(i>=n-1)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=1e7;
        for(int j=1;j<=nums[i];j++)
            ans=min(ans,solve(nums,i+j,dp)+1);
        
        return dp[i]= ans;
    }
    
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp);
        
    }
};