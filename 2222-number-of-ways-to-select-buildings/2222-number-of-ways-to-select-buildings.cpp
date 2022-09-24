class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
        int pre0=0,pre1=0,af0=0,af1=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                af0++;
            else
                af1++;
        }
        
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                ans+=pre0*af0;
                af1--;
                pre1++;
            }
            else
            {
                ans+=pre1*af1;
                af0--;
                pre0++;
            }
        }
        
        return ans;
    }
};