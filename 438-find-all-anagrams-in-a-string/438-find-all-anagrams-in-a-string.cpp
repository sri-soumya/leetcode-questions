class Solution {
public:
    
    bool check(vector<int> a,vector<int> b)
    {
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> in;
        int n=s.length(),m=p.length();
        if(m>n)
            return in;
        
        vector<int> a(26,0),b(26,0);
        for(int i=0;i<m;i++)
        {
            a[s[i]-'a']++;
            b[p[i]-'a']++;
        }
        
        if(check(a,b))
            in.push_back(0);
        
        for(int i=m;i<n;i++)
        {
            a[s[i]-'a']++;
            a[s[i-m]-'a']--;
            if(check(a,b))
                in.push_back(i-m+1);
        }
        
        return in;
    }
};