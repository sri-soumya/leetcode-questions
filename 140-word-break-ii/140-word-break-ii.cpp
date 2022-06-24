class Solution {
public:
    
    void solve(string &s,map<string,int> &mp,int i,vector<string> &a,string v)
    {
        int n=s.length();
        //cout<<i<<" "<<v<<endl;
        if(i==n)
        {
            if(v.length())
                a.push_back(v);
            return;
        }
        
        string z="";
        
        for(int k=i;k<n;k++)
        {
            z+=s[k];
            if(!mp.count(z))
                continue;
            string l=v;
            if(l.length())
                l+=" "+z;
            else
                l=z;
            solve(s,mp,k+1,a,l);
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& d) {
        
        int n=s.length();
        
        map<string,int> mp;
        
        for(auto x:d)
        {
            mp[x]++;
        }
        
        vector<string> c;
        
        solve(s,mp,0,c,"");
            
       return c; 
    }
};