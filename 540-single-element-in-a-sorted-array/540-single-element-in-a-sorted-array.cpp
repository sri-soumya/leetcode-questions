class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        
        int l=0,u=nums.size()-2;
        while(l<=u)
        {
            int m=(l+u)/2;
            if(nums[m]==nums[m^1])
                l=m+1;
            else
                u=m-1;
        }
        
        return nums[l];
    }
};