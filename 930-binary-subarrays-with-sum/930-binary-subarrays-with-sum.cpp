class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
     
        int n=nums.size(),s1=0,s2=0,ans=0,j1=0,j2=0;
        
        if(goal==0)
        {
            int c=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                    c++;
                else
                {
                    ans+=(c*(c+1))/2;
                    c=0;
                }
            }
            ans+=(c*(c+1))/2;
            return ans;
        }
        
        for(int i=0;i<n;i++)
        {
            while(j1<n&&s1<goal)
            {
                s1+=nums[j1++];
            }
            
            while(j2<n&&s2<=goal)
            {
                s2+=nums[j2++];
                if(s2>goal)
                {
                    s2--;
                    j2--;
                    break;
                }
            }
            
            if(s2<goal)
                break;
            
            ans+=j2-j1+1;
            
            s1-=nums[i];
            s2-=nums[i];
            
            
        }
        
        return ans;
    }
};