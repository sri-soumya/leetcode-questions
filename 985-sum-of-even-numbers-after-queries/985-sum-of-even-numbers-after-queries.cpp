class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int s=0;
        for(auto x:nums)
        {
            if(x%2==0)
                s+=x;
        }
        
        for(auto x:queries)
        {
            if(nums[x[1]]%2==0)
                s-=nums[x[1]];
            nums[x[1]]+=x[0];
            if(nums[x[1]]%2==0)
                s+=nums[x[1]];
            ans.push_back(s);
        }
        
        return ans;
    }
};