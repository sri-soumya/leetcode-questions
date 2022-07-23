class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();
        int j1=0,j2=0,c1=0,c2=0,ans=0;
        for(int i=0;i<n;i++)
        {
            while(c1<k&&j1<n)
            {
                if(nums[j1]%2)
                    c1++;
                j1++;
            }
            
            while(c2<=k&&j2<n)
            {
                if(nums[j2]%2)
                    c2++;
                j2++;
                if(c2>k)
                {
                    c2--;
                    j2--;
                    break;
                }
            }
            
            if(c2<k)
                break;
            
            ans+=j2-j1+1;
            
            if(nums[i]%2)
            {
                c1--;
                c2--;
            }

        }
        
        return ans;
        
    }
};