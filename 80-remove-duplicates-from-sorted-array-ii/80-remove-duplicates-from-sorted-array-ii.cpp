class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(auto j:nums)
        {
            if(i<2||j>nums[i-2])
                nums[i++]=j;
        }
        
        return i;
    }
};