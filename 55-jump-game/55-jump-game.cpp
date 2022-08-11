class Solution {
public:
    bool canJump(vector<int>& nums) {
     
        int n=nums.size(),l=n-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(i+nums[i]>=l)
                l=i;
        }
        
        return l==0;
    }
};