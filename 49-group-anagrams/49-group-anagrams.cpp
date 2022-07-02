#define ff first
#define ss second
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        
        int n=a.size();
        
        vector<pair<string,int>> strs;
        
        for(int i=0;i<n;i++)
            strs.push_back({a[i],i});
        
        for(int i=0;i<n;i++)
            sort(strs[i].ff.begin(),strs[i].ff.end());
        
        sort(strs.begin(),strs.end());
        
        vector<vector<string>> ans;
        int c=0;
        ans.push_back({a[strs[0].ss]});
        
        for(int i=1;i<n;i++)
        {
            if(strs[i].ff==strs[i-1].ff)
                ans[c].push_back(a[strs[i].ss]);
            else
            {
                ans.push_back({a[strs[i].ss]});
                c++;
            }
        }
        
        return ans;
        
    }
};