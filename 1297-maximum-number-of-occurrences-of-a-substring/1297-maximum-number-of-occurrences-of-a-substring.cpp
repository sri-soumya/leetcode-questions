class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int i=0,j=0,n=s.size(),ans=0;
        map<string,int> mp1;
        map<char,int> mp;
        while(i<n)
        {
            //cout<<i<<" "<<j<<endl;
            int l=j-i;
            if(l>=minSize&&l<=maxSize&&mp.size()<=maxLetters)
            {
                string a=s.substr(i,l);
                mp1[a]++;
                ans=max(ans,mp1[a]);
            }
            
            if(l<minSize&&j<n)
            {
                mp[s[j]]++;
                j++;
            }
            
            else
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            
        }
        
        return ans;
    }
};