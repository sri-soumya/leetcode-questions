class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int> mp;
        
        for(auto x:nums)
        {
            if(x)
                mp[x]++;
        }
        
        return mp.size();
    }
};