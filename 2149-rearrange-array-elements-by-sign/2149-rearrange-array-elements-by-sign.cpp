class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> a;
        vector<int> po,ne;
        
        int n=nums.size();
        int m=n/2;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
                po.push_back(nums[i]);
            else
                ne.push_back(nums[i]);
        }
        
        for(int i=0;i<m;i++)
        {
            a.push_back(po[i]);
            a.push_back(ne[i]);
        }
        
        return a;
        
        
    }
};