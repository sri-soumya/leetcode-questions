class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length(),i=0,j=0,ans=INT_MIN;
        unordered_map<char,int> mp;
        
        while(i<n&&j<n)
        {
            if(!mp.count(s[j])||mp[s[j]]<i)
            {
                mp[s[j]]=j;
                j++;
                ans=max(ans,j-i);
                
            }
            
            else
            {
                ans=max(ans,j-i);
                i=mp[s[j]]+1;
                mp[s[j]]=j;
                j++;
            }
        }
        //ans=max(ans,j-i);
        if(ans==INT_MIN)
            return 0;
        return ans;
    }
};