class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size(),j=0,ans=INT_MIN,s=0,sum=0;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        x=sum-x;
        
        if(x<0)
            return -1;
        
        for(int i=0;i<n;i++)
        {
            while(j<n&&s<x)
            {
                s+=nums[j];
                j++;
            }
            
            if(s==x)
                ans=max(ans,j-i);
            s-=nums[i];
        }
        
        if(ans==INT_MIN)
            return -1;
        return n-ans;
    }
};