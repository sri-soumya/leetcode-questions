class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans=0,n=s.size(),j=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            while(j<n)
            {
                if(mp.count(s[j]))
                    break;
                mp[s[j]]++;
                j++;
            }
            
            ans=max(ans,j-i);
            mp.erase(s[i]);
        }
        
        return ans;
        
    }
};