class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n=s.length();
        
        map<char,char> mp,mp2;
        
        for(int i=0;i<n;i++)
        {
            if(mp.count(t[i])==0&&mp2.count(s[i])==0)
            {
                mp[t[i]]=s[i];
                mp2[s[i]]=t[i];
                continue;
            }
            if(mp[t[i]]!=s[i]||mp2[s[i]]!=t[i])
                return false;
            
        }
        
        return true;
        
    }
};