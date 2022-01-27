class Solution {
public:
    int myAtoi(string s) {
        
        int i=0;
        while(i<s.length()&&s[i]==' ')
            i++;
        s=s.substr(i);
        int sign=1;
        long long int p = pow(2,31)-1;
        if(s.length()&&s[0]=='-'||s[0]=='+')
        {
            if(s[0]=='-')
                sign=-1;
            s=s.substr(1);
        }
        
        long long int ans=0;
        
        i=0;
        
        while(i<s.length()&&s[i]>='0'&&s[i]<='9')
        {
            
            ans=ans*10+(s[i]-'0');
            if(sign*ans>p)
                return (int)p;
            else if(sign*ans<-1*p-1)
                return (int)-1*p-1;
            
            i++;
        }
        
        ans*=sign;
        return (int)ans;
        
    }
};