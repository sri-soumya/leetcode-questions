class Solution {
public:
    
    bool solve(string s1,string s2, map<string,bool> &mp)
    {
        int n=s1.length(),m=s2.length();
        if(n!=m)
            return false;
        if(n==1)
            return s1==s2;
        
        string z=s1+"|"+s2;
        if(mp.count(z))
            return mp[z];
        for(int k=1;k<n;k++)
        {
            bool op1=solve(s1.substr(0,k),s2.substr(0,k),mp)&&solve(s1.substr(k),s2.substr(k),mp);
            bool op2=solve(s1.substr(0,k),s2.substr(n-k),mp)&&solve(s1.substr(k),s2.substr(0,n-k),mp);
            if(op1||op2)
                return mp[z]= true;
        }
        
        return mp[z]= false;
    }
    
    bool isScramble(string s1, string s2) {
        
        
        map<string,bool> mp;
        return solve(s1,s2,mp);
        
    }
};