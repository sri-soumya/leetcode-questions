class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        map<char,int> x;
        int c=0,m=0;
        for(int i=0;i<n;i++)
        {
            if(x.count(s[i])==0)
                c++;
            else
                c=min(i-x[s[i]],c+1);
            m=max(m,c);
            cout<<m<<endl;
            x[s[i]]=i;
        }
        
        return m;
        
        
    }
};