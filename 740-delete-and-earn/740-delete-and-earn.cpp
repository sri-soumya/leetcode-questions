class Solution {
public:
    
    int solve(vector<int> &nums,map<int,int> &mp,int in,vector<int> &dp)
    {   
        if(in<0)
            return 0;
        
        if(dp[in]!=-1)
            return dp[in];
        
        int in1=in-mp[nums[in]]-(mp.count(nums[in]-1)?mp[nums[in]-1]:0);
        int op1=mp[nums[in]]*nums[in]+solve(nums,mp,in1,dp);
        int in2=in-mp[nums[in]];
        int op2=solve(nums,mp,in2,dp);
        return dp[in]= max(op1,op2);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int> dp(n,-1);
        return solve(nums,mp,n-1,dp);
    }
};