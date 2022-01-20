class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        bool f=false;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>=nums[i+1])
                continue;
            
            f=true;
            int in;
            for(int j=n-1;j>=i+1;j--)
            {
                if(nums[j]>nums[i])
                {
                    in=j;
                    break;
                }
            }
            
            swap(nums[i],nums[in]);
            
            reverse(nums.begin()+i+1,nums.end());
            break;
        }
        
        if(!f)
            reverse(nums.begin(),nums.end());
        
        //return nums;
        
    }
};