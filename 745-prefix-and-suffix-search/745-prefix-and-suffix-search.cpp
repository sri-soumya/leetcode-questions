class WordFilter {
    
    unordered_map<string,int> mp; 
    
public:
    
    vector<string> prefix(string s)
    {
        int n=s.size();
        string a="";
        vector<string> b(n);
        for(int i=0;i<s.size();i++)
        {
            a+=s[i];
            b[i]=a;
        }
        
        return b;
    }
    
    vector<string> suffix(string s)
    {
        int n=s.size();
        string a="";
        vector<string> b(n);
        for(int i=s.size()-1;i>=0;i--)
        {
            a=s[i]+a;
            b[i]=a;
        }
        
        return b;
    }
    
    WordFilter(vector<string>& a) {
        
        int n=a.size();
        
        for(int i=0;i<n;i++)
        {
            vector<string> p;vector<string> s;
            p=prefix(a[i]);
            s=suffix(a[i]);
            
            for(auto j:p)
            {
                for(auto k:s)
                    mp[j+"|"+k]=i;
            }
        }
        
        
        
    }
    
    int f(string p, string s) {
        
        if(mp.count(p+"|"+s))
            return mp[p+"|"+s];
        return -1;
        
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */