class Solution {
public:
    string reverseVowels(string s) {
        string a="";
        
        for(auto x:s)
        {
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
                a=x+a;
        }
        int in=0;
        for(auto &x:s)
        {
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
                x=a[in++];
        }
        
        return s;
    }
};