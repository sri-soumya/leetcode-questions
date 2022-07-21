class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n=nums.size(),ans=0;
        
        deque<int> minq,maxq;
        
        int l=0;
        
        for(int i=0;i<n;i++)
        {
            while(minq.size()&&nums[i]<minq.back())
                minq.pop_back();
            
            minq.push_back(nums[i]);
            
            while(maxq.size()&&nums[i]>maxq.back())
                maxq.pop_back();
            
            maxq.push_back(nums[i]);
            
            while(maxq.front()-minq.front()>limit)
            {
                if(nums[l]==minq.front())
                    minq.pop_front();
                if(nums[l]==maxq.front())
                    maxq.pop_front();
                l++;
            }
            
            ans=max(ans,i-l+1);
        }
        
        return ans;
    }
};