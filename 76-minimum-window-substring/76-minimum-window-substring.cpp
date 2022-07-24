#define ff first
#define ss second
class Solution {
public:
    
    bool check(vector<int> &bf,vector<int> &sf)
    {
        for(int i=0;i<256;i++)
        {
            if(sf[i]==0)
                continue;
            if(sf[i]>bf[i])
                return false;
        }
        
        return true;
    }
    
    
    string minWindow(string s, string t) {
        
        int m=s.length(),n=t.length(),j=0;
        
        if(n>m)
            return "";
        
        string ans=s+"#";
        pair<int,int> a={-1e6,1e6};
        vector<int> bf(256,0),sf(256,0);
        for(int i=0;i<n;i++)
        {
            sf[t[i]]++;
        }
        
        //cout<<check(bf,sf);
        
        for(int i=0;i<m;i++)
        {
            while(j<m&&!check(bf,sf))
            {
                bf[s[j]]++;
                j++;
            }
            
            
            if(!check(bf,sf))
                break;
            if(j-i<a.ss-a.ff)
            {
                a={i,j};
            }
            
            bf[s[i]]--;
        }
        
       if(a.ss==1e6)
           return "";
        
        return s.substr(a.ff,a.ss-a.ff);
    }
};