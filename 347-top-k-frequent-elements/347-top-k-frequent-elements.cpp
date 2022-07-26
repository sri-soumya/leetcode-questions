#define pii pair<int,int>
#define ff first
#define ss second
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pii,vector<pii>,greater<pii>> q;
        
        for(auto x:mp)
        {
            if(q.size()<k)
            {
                q.push({x.ss,x.ff});
            }
            
            else if(x.ss>q.top().ff)
            {
                q.pop();
                q.push({x.ss,x.ff});
            }
        }
        
        while(q.size())
        {
            ans.push_back(q.top().ss);
            q.pop();
        }
        
        return ans;
    }
};