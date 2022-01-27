class Solution {
public:
    
    void rev(string &s,int b,int n)
    {
        n--;
        while(b<n)
        {
            swap(s[b],s[n]);
            b++;n--;
        }
    }
    
    
    string reverseWords(string s) {
        
        s+=" ";
        int l=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                rev(s,l,i);
                l=i+1;
                int c=i;
                while(c<s.length()&&s[c]==' ')
                {
                    c++;
                }
                s=s.substr(0,i+1)+((c<s.length())?s.substr(c):"");
                // while(i<s.length()&&s[i]==' ')
                // {
                //     i++;
                // }
            }
            
            
        }
        
        reverse(s.begin(),s.end());
        
        if(s[0]==' ')
            s=s.substr(1);
        if(s[s.length()-1]==' ')
            s=s.substr(0,s.length()-1);
        
        return s;
        
    }
};