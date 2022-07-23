class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int> mp;
        mp[0]++;
        int n=nums.size(),ans=0,s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            if(mp.count(s-goal))
                ans+=mp[s-goal];
            mp[s]++;
        }
        
        return ans;
    }
};