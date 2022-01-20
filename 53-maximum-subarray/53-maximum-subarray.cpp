class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane
        int n=nums.size();
        int s=0;
        int maxi=nums[0];
        
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            maxi=max(s,maxi);
            if(s<0)
                s=0;
        }
        
        return maxi;
        
    }
};