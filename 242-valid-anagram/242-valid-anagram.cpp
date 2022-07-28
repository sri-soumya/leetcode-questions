class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n=s.size(),m=t.size();
        
        if(m!=n)
            return false;
        
        vector<int> freq(26,0);
        
        for(int i=0;i<n;i++)
        {
            int x=s[i]-'a',y=t[i]-'a';
            freq[x]++;
            freq[y]--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
                return false;
        }
        
        return true;
    }
};