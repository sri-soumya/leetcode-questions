class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n=nums.size(),ans=0;
        int x=0,y=0;
        
        unordered_map<int,int> small,large;
        
        for(int i=0;i<n;i++)
        {
            while(small.size()<=k-1&&x<n)
            {
                small[nums[x]]++;
                x++;
                if(small.size()==k)
                {
                    x--;
                    small.erase(nums[x]);
                    break;
                }
            }
            
            while(large.size()<=k&&y<n)
            {
                large[nums[y]]++;
                y++;
                
                if(large.size()==k+1)
                {
                    y--;
                    large.erase(nums[y]);
                    break;
                }
            }
            
            if(large.size()<k)
                break;
            
            if(k>1)
                ans+=y-x;
            else
                ans+=y-i;
            
            small[nums[i]]--;
            large[nums[i]]--;
            
            if(small[nums[i]]==0)
                small.erase(nums[i]);
            if(large[nums[i]]==0)
                large.erase(nums[i]);
            
            // l++;
        }
        
        return ans;
    }
};