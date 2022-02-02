class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            
            int j=i+1,k=n-1;
            while(j<k)
            {
                int s=nums[i]+nums[j]+nums[k];
                if(s<0)
                    j++;
                else if(s>0)
                    k--;
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(++j<n&&nums[j]==nums[j-1]);
                    while(--k>j&&nums[k]==nums[k+1]);
                }
            }
        }
        
        return ans;
    }
};