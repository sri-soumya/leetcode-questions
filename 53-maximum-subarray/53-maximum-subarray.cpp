class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
        int n=nums.size();
        int a[n];
        
        a[0]=nums[0];
        int maxi=a[0];
        
        for(int i=1;i<n;i++)
        {
            a[i]=max(nums[i],a[i-1]+nums[i]);
            maxi=max(maxi,a[i]);
        }
        return maxi;
    }
};