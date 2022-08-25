class Solution {
public:
    bool canConstruct(string a, string b) {
        int n=a.size(),m=b.size();
        vector<int> f(26,0);
        
        for(auto x:b)
        {
            f[x-'a']++;
        }
        
        for(auto x:a)
        {
            f[x-'a']--;
            if(f[x-'a']<0)
                return false;
        }
        
        return true;
    }
};