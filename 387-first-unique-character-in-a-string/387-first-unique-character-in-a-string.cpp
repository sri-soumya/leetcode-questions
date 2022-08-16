class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26,-1);
        
        for(int i=0;i<s.size();i++)
        {
            int c=s[i]-'a';
            if(f[c]==-1)
                f[c]=i;
            else
                f[c]=INT_MIN;
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<26;i++)
        {
            if(f[i]>=0)
                ans=min(f[i],ans);
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};