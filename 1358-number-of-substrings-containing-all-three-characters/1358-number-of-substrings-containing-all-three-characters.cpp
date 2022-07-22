class Solution {
public:
    int numberOfSubstrings(string s) {

        int l=0,r=0,ans=0,n=s.length();
        
        map<char,int> mp;
        
        while(l<n)
        {
            while(mp.size()<3&&r<n)
            {
                mp[s[r]]++;
                r++;
            }
            
            if(mp.size()<3)
                break;
            
            ans+=n-r+1;
            
            mp[s[l]]--;
            if(mp[s[l]]==0)
                mp.erase(s[l]);
            l++;
        }
        
        return ans;
    }
};