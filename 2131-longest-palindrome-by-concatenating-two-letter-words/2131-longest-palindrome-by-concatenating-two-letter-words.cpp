class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int c=0;
        
        for(auto x:words)
        {
            if(x[0]==x[1])
            {
                mp[x]++;
                continue;
            }
            
            string k=x;
            reverse(x.begin(),x.end());
            if(mp[x]>0)
            {
                c+=4;
                mp[x]--;
            }
            else
                mp[k]++;
        }
        
        int z=0;
        
        for(auto x:mp)
        {
            if((x.first)[0]!=(x.first)[1])
                continue;
            if(x.second%2&&x.second>z)
            {
                if(z)
                    c+=(z-1)*2;
                z=x.second;
            }
            else if(x.second%2)
            {
                c+=(x.second-1)*2;
            }
            else
            {
                c+=x.second*2;
            }
        }
        
        return c+z*2;
    }
};