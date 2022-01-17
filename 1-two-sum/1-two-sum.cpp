class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> a;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i]))
            {
                ans.push_back(i);
                ans.push_back(a[target-nums[i]]);
                break;
            }
            
            a[nums[i]]=i;
        }
        
        return ans;
        
    }
};