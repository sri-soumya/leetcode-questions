class Solution {
public:
    
    bool check(string &a,string &b)
    {
        int n=a.length();
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        
        for(int i=0;i<n;i++)
        {
            if(!mp1.count(b[i])&&!mp2.count(a[i]))
            {
                mp1[b[i]]=a[i];
                mp2[a[i]]++;
            }
            else if(mp1[b[i]]!=a[i])
                return false;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        int n=pattern.length(),m=words.size();
        vector<string> ans;
        
        for(auto x:words)
        {
            if(check(x,pattern))
                ans.push_back(x);
        }
        
        return ans;
    }
};