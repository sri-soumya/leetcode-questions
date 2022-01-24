class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        map<char,int> x;
        /*int c=0,m=0;
        for(int i=0;i<n;i++)
        {
            if(x.count(s[i])==0)
                c++;
            else
                c=min(i-x[s[i]],c+1);
            m=max(m,c);
            //cout<<m<<endl;
            x[s[i]]=i;
        }
        
        return m;*/
        
        //same concept but the code below is more understandable
        
        int l=0,r=0,m=0;
        
        while(r<n)
        {
            
            if(x.count(s[r])==0)
                r++;
            else if(x[s[r]]<l)
                r++;
            else
                l=x[s[r]]+1;
            x[s[r-1]]=r-1;
            m=max(m,r-l);
            //cout<<l<<" "<<r<<endl;
        }
        
        return m;
        
        
    }
};