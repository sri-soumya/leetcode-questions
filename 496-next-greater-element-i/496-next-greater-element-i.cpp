class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size(),m=nums2.size();
        
        stack<int> s;
        
        vector<int> a;
        unordered_map<int,int> mp;
        for(int i=m-1;i>=0;i--)
        {
            while(s.size()&&s.top()<nums2[i])
            {
                s.pop();
            }
            
            if(!s.size())
                mp[nums2[i]]=-1;
            else
                mp[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        
        for(auto x:nums1)
        {
            a.push_back(mp[x]);
        }
        
        return a;
    }
};