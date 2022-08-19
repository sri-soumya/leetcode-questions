class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int n=nums.size();
        
        unordered_map<int,int> f,mp;
        
        for(int i=0;i<n;i++)
            f[nums[i]]++;
        
        for(int i=0;i<n;i++)
        {
            if(f[nums[i]]==0)
                continue;
            
            if(mp[nums[i]]==0)
            {
                if(f[nums[i]+1]==0||f[nums[i]+2]==0)
                    return false;
                mp[nums[i]+3]++;
                f[nums[i]]--;
                f[nums[i]+1]--;
                f[nums[i]+2]--;
            }
            else
            {
                f[nums[i]]--;
                mp[nums[i]]--;
                mp[nums[i]+1]++;
            }
        }
        
        return true;
        
    }
};