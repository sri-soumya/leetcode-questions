class Solution {
public:
    int romanToInt(string s) {
       
        map<char,int> x;
        x['I']=1;x['V']=5;x['X']=10;x['L']=50;x['C']=100;x['D']=500;x['M']=1000;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(i+1>=n||x[s[i]]>=x[s[i+1]])
                ans+=x[s[i]];
            else if(i+1<n&&x[s[i]]<x[s[i+1]])
            {
                ans+=x[s[i+1]]-x[s[i]];
                i++;
            }
        }
        
        return ans;
        
    }
};