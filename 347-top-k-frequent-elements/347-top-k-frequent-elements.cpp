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
        
        vector<vector<int>> freq(n+1);
        
        for(auto x:mp)
        {
            freq[x.ss].push_back(x.ff);
        }
        
        for(int i=freq.size()-1;i>=1;i--)
        {
            for(int j=0;j<freq[i].size();j++)
            {
                ans.push_back(freq[i][j]);
                if(ans.size()==k)
                    break;
            }
            
            if(ans.size()==k)
                break;
        }
        
        return ans;
    }
};