class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;)
            {
                int t=target-nums[i]-nums[j];
                int f=j+1,s=n-1;
                
                while(f<s)
                {
                     
                    if(nums[s]+nums[f]<t)
                        f++;
                    else if(nums[s]+nums[f]>t)
                        s--;
                    else
                    {
                        
                        ans.push_back({nums[i],nums[j],nums[f],nums[s]});
                        f++;
                        s--;
                         while(f<s&&nums[f]==nums[f-1])
                         f++;
                         while(f<s&&nums[s]==nums[s+1])
                         s--;
                    }
                }
                j++;
                 while(j<n&&nums[j]==nums[j-1])
                    j++;
            }
        }
        
        return ans;
    }
};