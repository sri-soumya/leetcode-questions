class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(),m;
        
        for(int i=0;i<n;i++)
        {
            int x=abs(nums[i])-1;
            if(nums[x]<0)
                m=x+1;
            else
                nums[x]*=-1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                return {m,i+1};
        }
        
        return {};
    }
};