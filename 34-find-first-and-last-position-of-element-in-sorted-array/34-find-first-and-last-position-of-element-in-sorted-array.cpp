class Solution {
public:
    
    int firstoccur(vector<int> &nums,int x)
    {
        int l=0,h=nums.size()-1,ans=-1;
        
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]==x)
                ans=m;
            if(nums[m]>=x)
            {
                h=m-1;
            }
            else
                l=m+1;
        }
        
        return ans;
    }
    
    int lastoccur(vector<int> &nums,int x)
    {
        int l=0,h=nums.size()-1,ans=-1;
        
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]==x)
                ans=m;
            if(nums[m]<=x)
            {
                l=m+1;
            }
            else
                h=m-1;
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int x=firstoccur(nums,target);
        if(x==-1)
            return {-1,-1};
        int y=lastoccur(nums,target);
        
        return {x,y};
        
    }
};