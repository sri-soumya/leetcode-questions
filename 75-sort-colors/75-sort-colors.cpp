class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i=0,m=0,j=nums.size()-1;
        
        while(m<=j)
        {
            if(nums[m]==1)
            {
                m++;
                continue;
            }
            
            else if(nums[m]==0)
            {
                swap(nums[i],nums[m]);
                i++;
                m++;
            }
            
            else
            {
                swap(nums[m],nums[j]);
                j--;
            }
        }
        
        
        
    }
};