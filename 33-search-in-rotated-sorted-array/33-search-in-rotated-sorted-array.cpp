class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,u=nums.size()-1;
        
        while(l<=u)
        {
            
            int m=(l+u)/2;
            
            if(nums[m]==target)
                return m;
            if(nums[l]<=nums[m])
            {
                if(target>=nums[l]&&target<=nums[m])
                    u=m-1;
                else
                    l=m+1;
            }
            else
            {
                if(target>=nums[m]&&target<=nums[u])
                    l=m+1;
                else
                    u=m-1;
            }
            
        }
        
        return -1;
    }
};