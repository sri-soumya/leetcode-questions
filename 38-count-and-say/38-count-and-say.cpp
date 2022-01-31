class Solution {
public:
    
    string solve(int n)
    {
        if(n==1)
            return "1";
        string s=solve(n-1)+" ";
        
        int k=1;
        char c=s[0];
        string a="";
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==c)
                k++;
            else
            {
                a+=to_string(k)+c;
                c=s[i];
                k=1;
            }
        }
        
        return a;
        
    }
    
    string countAndSay(int n) {
        
        return solve( n);
        
    }
};