class Solution {
public:
    
    
    int solve(string &s,int i,int j)
    {
        int c=0,n=s.size();
        while(i>=0&&j<n&&s[i]==s[j])
        {
            c++;
            i--;
            j++;
        }
        
        return c;
    }
    
    int countSubstrings(string s) {
        
        int n=s.length(),ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=solve(s,i,i);
            ans+=solve(s,i,i+1);
        }
        
        return ans;
    }
};