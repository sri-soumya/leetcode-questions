class Solution {
public:
    
    bool pal(string s)
    {
        int n=s.size();
        for(int i=0;i<s.size();i++)
            if(s[i]!=s[n-i-1])
                return false;
        return true;
    }
    
    void solve(string s,vector<vector<string>>& a,int in,vector<string> d)
    {
        int n=s.length();
        if(in>=n)
        {
            a.push_back(d);
            return;
        }
        
        for(int i=n-1;i>=in;i--)
        {
            string b=s.substr(in,i-in+1);
            if(pal(b))
            {
                d.push_back(b);
                solve(s,a,i+1,d);
                d.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> a;
        vector<string> d;
        solve(s,a,0,d);
        
        return a;
        
    }
};