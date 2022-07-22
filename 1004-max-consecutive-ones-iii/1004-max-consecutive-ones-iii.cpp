class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n=nums.size(),ans=0,l=0,r=0;
        
        while(l<n)
        {
            while(r<n)
            {
                if(nums[r]==1)
                    r++;
                else if(nums[r]==0&&k)
                {
                    k--;
                    r++;
                }
                else
                    break;
                    
            }
            
            ans=max(ans,r-l);
            if(nums[l]==0)
            {
                k++;
            }
            l++;
        }
        
        return ans;
        
    }
};