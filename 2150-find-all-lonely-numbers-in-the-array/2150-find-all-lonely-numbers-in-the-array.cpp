class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        map<int,int> x;
        int n=nums.size();
        vector<int> a;
        
        for(int i=0;i<n;i++)
            x[nums[i]]++;
        
        
        for(int i=0;i<n;i++)
        {
            if(x[nums[i]]==1&&!x.count(nums[i]+1)&&!x.count(nums[i]-1))
                a.push_back(nums[i]);
        }
        
        return a;
        
    }
};