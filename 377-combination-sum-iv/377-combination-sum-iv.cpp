#define ll unsigned long long int
class Solution {
public:
    
    int solve(vector<int> &nums,int t,vector<int> &dp)
    {
        if(t==0)
            return 1;
        if(t<0)
            return 0;
        
        if(dp[t]!=-1)
            return dp[t];
        
        int n=nums.size(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans+=solve(nums,t-nums[i],dp);
        }
        
        return dp[t]= ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<ll> dp(target+1,0);
        //return solve(nums,target,dp);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i]+=(i-nums[j]>=0)?dp[i-nums[j]]:0;
            }
        }
        
        return dp[target];
    }
};