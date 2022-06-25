class Solution {
public:
    int findSubstringInWraproundString(string p) {
        
        int n=p.length(),a=0,z=0;
        vector<int> s(26,0);
        
        for(int i=0;i<n;i++)
        {
            if(i>0&&(((p[i-1]-'a'+1)%26))==p[i]-'a')
            {
                z++;
            }
            else
            {
                z=1;
            }
            if(z>s[p[i]-'a'])
            {
                a+=z-s[p[i]-'a'];
                s[p[i]-'a']=z;
            }
        }
        
        return a;
        
    }
};