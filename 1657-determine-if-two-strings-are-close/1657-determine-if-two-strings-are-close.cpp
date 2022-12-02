class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26,0),b(26,0);
        
        int c1=0,c2=0,n=word1.size(),m=word2.size();
        
        if(n!=m)
            return 0;
        
        for(int i=0;i<n;i++)
        {
            int x=word1[i]-'a';
            int y=word2[i]-'a';
            
            if(!a[x])
                c1++;
            if(!b[y])
                c2++;
            
            a[x]++;
            b[y]++;
        }
        
        if(c1!=c2)
            return 0;
        
        for(int i=0;i<26;i++)
        {
            if(a[i]&&!b[i]||!a[i]&&b[i])
                return 0;
        }
        
        for(int i=0;i<26;i++)
        {
            if(!a[i])
                continue;
            int f=0;
            for(int j=0;j<26;j++)
            {
                if(a[i]==b[j])
                {
                    f=1;
                    b[j]=0;
                    break;
                }
            }
            
            if(!f)
                return 0;
        }
        
        return 1;
    }
};