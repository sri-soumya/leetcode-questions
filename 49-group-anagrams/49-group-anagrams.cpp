class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
     
        int n=a.size();
        vector<string> s=a;
        map<string,vector<string>> mp;
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++)
        {
            sort(a[i].begin(),a[i].end());
            mp[a[i]].push_back(s[i]);
        }
        
        for(auto it:mp)
            ans.push_back(it.second);
        
        return ans;
        
    }
};