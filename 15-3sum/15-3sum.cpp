class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0&&nums[i-1]==nums[i])
                continue;
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    if(j>i+1&&nums[j]==nums[j-1])
                    {
                        j++;
                        //k--;
                        continue;
                    }
                    if(k<nums.size()-1&&nums[k]==nums[k+1])
                    {
                        k--;
                        continue;
                    }
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                    k--;
                else
                    j++;
            }
        }
        
        return ans;
        
    }
};