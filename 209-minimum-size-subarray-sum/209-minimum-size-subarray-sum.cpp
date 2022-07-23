class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     
        int n=nums.size(),s=0,j=0,ans=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            while(j<n&&s<target)
            {
                s+=nums[j++];
            }
            
            if(s<target)
                break;
            
            ans=min(ans,j-i);
            s-=nums[i];
        }
        
        if(ans==INT_MAX)
            return 0;
        
        return ans;
    }
};