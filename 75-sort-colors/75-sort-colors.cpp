class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int z=0;
        int t=n-1;
        
        for(int i=0;i<n;)
        {
            if(i>t)
                break;
            if(nums[i]==1)
            {
                i++;
                continue;
            }
            if(nums[i]==0)
            {
                swap(nums[i],nums[z]);
                z++;
                i++;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[t]);
                t--;
            }
            
        }
        
    }
};