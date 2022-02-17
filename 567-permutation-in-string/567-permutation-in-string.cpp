class Solution {
public:
    
    bool check(vector<int> a,vector<int> b)
    {
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return false;
        
        return true;
    }
    
    bool checkInclusion(string s2, string s1) {
        
        int n=s1.length(),m=s2.length();
        if(m>n)
            return false;
        vector<int> a(26,0);
        vector<int> b(26,0);
        
        for(int i=0;i<m;i++)
        {
            a[s2[i]-'a']++;
            b[s1[i]-'a']++;
        }
        
        if(check(a,b))
            return true;
        
        for(int i=m;i<n;i++)
        {
            b[s1[i-m]-'a']--;
            b[s1[i]-'a']++;
            if(check(a,b))
                return true;
        }
        
        return false;
        
    }
};