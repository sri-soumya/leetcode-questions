#define pii pair<int,int>
#define ff first
#define ss second
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n=nums.size();
        stack<pii> pg;
        int mini=nums[0];
        
        for(int i=1;i<n;i++)
        {
            while(pg.size()&&nums[i]>=pg.top().ff)
            {
                pg.pop();
            }
            
            if(pg.size()&&pg.top().ss<nums[i])
                return true;
            
            pg.push({nums[i],mini});
            mini=min(mini,nums[i]);
        }
        
        return false;
    }
};