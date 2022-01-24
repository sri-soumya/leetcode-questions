class Solution {
public:
    
    int solve(vector<int> nums)
    {
        int n=nums.size(),lb=0,ub=n-1;
        
        while(lb<=ub)
        {
            int m=(lb+ub)/2;
            if(m-1>=0&&nums[m]<nums[m-1])
                return nums[m];
            if(m+1<n&&nums[m]>nums[m+1])
                return nums[m+1];
            if(nums[lb]<nums[m])
                lb=m+1;
            else
                ub=m-1;
        }
        
        return nums[0];
    }
    
    int findMin(vector<int>& nums) {
       return solve(nums);
    }
};