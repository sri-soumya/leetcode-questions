class Solution {
public:
    string robotWithString(string s) {
        vector<int> f(26,0);
        
        int n=s.length();
        
        for(auto x:s)
        {
            f[x-'a']++;
        }
        string l="",ans="";
        for(auto x:s)
        {
            l+=x;
            f[x-'a']--;
            int c=0;
            
            while(c<26&&!f[c])
            {
                c++;
            }
            
            while(true)
            {
                int in=l.length()-1;
                if(in<0||l[in]-'a'>c)
                    break;
                ans+=l[in];
                l.pop_back();
            }
        }
        
        return ans;
    }
};